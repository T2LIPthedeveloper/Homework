(define (domain logistics-locations)
    (:predicates (truck ?t)
        (package ?p)
        (location ?l)
        (free ?t)
        (carry ?t ?p)
        (at-loc ?o ?l)
    )
    (:action pick
        :parameters (?pkg ?loc ?trk)
        :precondition (and (
            (package ?pkg) (location ?loc) (truck ?trk)
            (at-loc ?trk ?loc) (at-loc ?pkg ?loc) (free ?trk)
        ))
        :effect (and (
            (carry ?trk ?pkg) 
            (not(at-loc ?trk ?loc)) 
            (not(at-loc ?pkg ?loc)) 
            (not(free ?trk))
        ))
    )
    (:action drop
        :parameters (?pkg ?loc ?trk)
        :precondition (and (
            (package ?pkg) (location ?loc) (truck ?trk)
            (not(at-loc ?pkg ?loc)) (at-loc ?trk ?loc) (not(free ?trk))
        ))
        :effect (and (
            (free ?trk)
            (at-loc ?pkg ?loc)
            (not(at-loc ?trk ?loc))
            (not(carry ?trk ?pkg))
        ))
    )
    (action move
        :parameters (?trk ?to ?from)
        :precondition (and (
            (at-loc ?trk ?from) (not(at-loc ?trk ?to))
        ))
        :effect (and
            (at-loc ?trk ?to) (not(at-loc ?trk ?from))
        )
    )
)