(ns coordinate-transformation)

(defn translate2d 
  "Returns a function making use of a closure to
   perform a repeatable 2d translation of a coordinate pair."
  [dx dy]
  (fn [x y] [(+ dx x) (+ dy y)])
  )

(defn scale2d 
  "Returns a function making use of a closure to
   perform a repeatable 2d scale of a coordinate pair."
  [sx sy]
  (fn [x y] [(* sx x) (* sy y)])
  )

(defn compose-transform
  "Create a composition function that returns a function that 
   combines two functions to perform a repeatable transformation."
  [f g]
  (fn [x y] (let [fs (f x y) x' (first fs) y' (second fs)]
              (g x' y')))
  )

(defn memoize-transform
  "Returns a function that memoizes the last result.
   If the arguments are the same as the last call,
   the memoized result is returned."
  [f]
  (let [mem (atom [[0 0] [0 0]])]
    (fn [x y]
      (if (= [x y] (get @mem 0))
        (get @mem 1)
        (get (reset! mem [[x y] (f x y)]) 1)
          ))))
