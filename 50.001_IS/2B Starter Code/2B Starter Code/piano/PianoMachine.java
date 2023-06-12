package piano;

import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;

import javax.sound.midi.MidiUnavailableException;

import midi.Midi;
import midi.Instrument;
import music.NoteEvent;
import music.Pitch;

public class PianoMachine {
	
	private Midi midi;
    private Instrument instrument;
    private int octave;
    private PossibleStates currState;
    //enum allows for different state changes to be tracked
    private List<NoteEvent> eventList;
    //list of events
    private List<Pitch> noteStack = new ArrayList<Pitch>();

    private final int max_oct_shift = 2;
    // max range
    private final Pitch defPitch = new Pitch(0);
    //default pitch constant
    
	/**
	 * constructor for PianoMachine.
	 * 
	 * initialize midi device and any other state that we're storing.
	 */
    public PianoMachine() {
    	try {
            midi = Midi.getInstance();
            this.instrument = Instrument.PIANO;
            this.octave = 0;
            this.currState = PossibleStates.normal;
        } catch (MidiUnavailableException e1) {
            System.err.println("Could not initialize midi device");
            e1.printStackTrace();
            return;
        }
    }
    

    public void beginNote(Pitch rawPitch) {
        //as pitch can be transposed a "currPitch" attribute is created to store the current pitch as called.
        // transposing the pitch by the octave = 12 semitones 
        Pitch currPitch = new Pitch(rawPitch.difference(defPitch)).transpose(this.octave * Pitch.OCTAVE);
        
        if (this.currState == PossibleStates.playback) {
            return;
        }
        if (!noteStack.contains(rawPitch)) {
            midi.beginNote(currPitch.toMidiFrequency(), this.instrument);
            noteStack.add(rawPitch);
        }

        if (this.currState == PossibleStates.recording) {
            NoteEvent event = new NoteEvent(currPitch, System.currentTimeMillis(), instrument, NoteEvent.Kind.start);
            //starts recording state
            eventList.add(event);
        }
        


    }
    
    public void endNote(Pitch rawPitch) {
    	Pitch currPitch = new Pitch(rawPitch.difference(defPitch)).transpose(this.octave * Pitch.OCTAVE);
        
        if (this.currState == PossibleStates.playback) {
            return;
        }

        if (noteStack.contains(rawPitch)) {
            midi.endNote(currPitch.toMidiFrequency(), this.instrument);
            noteStack.remove(rawPitch);
        }

        if (this.currState == PossibleStates.recording) {
            NoteEvent event = new NoteEvent(currPitch, System.currentTimeMillis(), instrument, NoteEvent.Kind.stop);
            //ends recording state for that note
            eventList.add(event);
        }
    }
    
    public void changeInstrument() {
        //changes instrument to next instrument in enum
        this.instrument = instrument.next();
    }
    
    public void shiftUp() {
        if (this.octave < max_oct_shift) {
            this.octave++;
        }
    }
    
    public void shiftDown() {
        if (this.octave > -max_oct_shift) {
            this.octave--;
        }
    }
    
    public boolean toggleRecording() {
        if (this.currState == PossibleStates.normal) {
            //normal, start recording
            this.currState = PossibleStates.recording;
            this.eventList = new LinkedList<NoteEvent>();
            //linked list used to travel one pointer at a time

            return true;

        } else if (this.currState == PossibleStates.recording) {
            //stop recording
            this.currState = PossibleStates.normal;
            return false;
        } else {
            //playback, cannot record
            return false;
        }

    }
    
    public void playback() {    	
        if (eventList == null || eventList.size() == 0 || this.currState != PossibleStates.normal) {
            //illegal to playback in any state other than default
            //null recording means that something must have gone wrong or nothing to play back
            return;
        }

        this.currState = PossibleStates.playback;

        try {
            recordPlayback();
        } 
        catch (MidiUnavailableException e) {
            e.printStackTrace();
            return;
            //exception handling for midi device
        }

        this.currState = PossibleStates.normal;
        //return to default after playback

    }

    private void recordPlayback() throws MidiUnavailableException {
        Midi recorder = Midi.getInstance();
        Iterator<NoteEvent> iter = eventList.iterator();
        NoteEvent currNoteEvent = iter.next();
        while (iter.hasNext()) {
            Pitch currPitch = currNoteEvent.getPitch();
            long currTime = currNoteEvent.getTime();
            Instrument currInst = currNoteEvent.getInstr();

            if (currNoteEvent.getKind() == NoteEvent.Kind.start) {
                //indicates start of note
                recorder.beginNote(currPitch.toMidiFrequency(), currInst);
            } else {
                recorder.endNote(currPitch.toMidiFrequency(), currInst);
            }

            currNoteEvent = iter.next();
            long waiting = (currNoteEvent.getTime() - currTime) / 10;
            
            Midi.rest((int) waiting);

        }

        //this accounts for all scenarios except final note.
        recorder.endNote(currNoteEvent.getPitch().toMidiFrequency(), currNoteEvent.getInstr());

    }

    //provides different states for the piano machine.
    private enum PossibleStates {
        recording, playback, normal
    }
}
