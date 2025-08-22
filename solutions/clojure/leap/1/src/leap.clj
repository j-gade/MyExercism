(ns leap)

(defn leap-year?
  "Returns whether a given year is a leap year."
  [year]
    (or (zero? (rem year 400))
        (and (zero? (rem year 4))
             (pos? (rem year 100)))))
