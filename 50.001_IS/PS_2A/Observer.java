import java.util.ArrayList;

//**SEE BELOW** modify AirPollutionAlert 
//Necessary Import statements here

// **** YOU DO NOT NEED TO MODIFY THIS PART OF THE CODE -------
interface Observer{
	void update(double airPollutionIndex);
}

class Subscriber implements Observer{
	private Subject subject;
	private String observerId;
	public static String outputMessage = "";
	
	public Subscriber(String observerId, Subject subject){
		this.subject=subject;
		this.observerId = observerId;		
		this.subject.register(this);		// register itself
	}

	@Override
	public void update(double airPollutionIndex) {
		String s = this.observerId + " received notification: " + airPollutionIndex;
		System.out.println(s);
		outputMessage += (s + " ");
	}
}

interface Subject{
	void register(Observer o);
	void unregister(Observer o);
	void notifyObservers();
}
//-------------------------------------------------------

//TODO: modify AirPollutionAlert to implement interface Subject, under Observer design pattern
class AirPollutionAlert implements Subject{
	private double airPollutionIndex;
    private ArrayList<Observer> observers;

    public AirPollutionAlert() {
       observers = new ArrayList<Observer>();
    }
	
	public void setAirPollutionIndex(double airPollutionIndex) {
		if (airPollutionIndex > 100) {
            this.airPollutionIndex = airPollutionIndex;
            notifyObservers();
        }
	}

    @Override
    public void register(Observer o) {
        observers.add(o);
    }

    @Override
    public void unregister(Observer o) {
        observers.remove(o);
    }

    @Override
    public void notifyObservers() {
        for (Observer o: observers)
            o.update(this.airPollutionIndex);
    }
}


/* Some information on test cases: 
 Test Cases 1, 3, 5 and 8 use an airPollutionIndex that is less than 100
 The rest use an airPollutionIndex that is larger than 100 */