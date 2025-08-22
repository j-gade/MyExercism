(ns interest-is-interesting)

(defn interest-rate
  "Returns the interest rate based on the specified balance."
  [balance]
  (cond
    (neg? balance)   -3.213
    (< balance 1000)  0.5
    (< balance 5000)  1.621
    :else             2.475
    )
  )

(defn interest-multiplier
  "Returns the decimal value to multiply by"
  [interest]
  (/ (if (neg? interest)
    (+' -100.0 interest)
    (+' 100.0 interest)
    ) 100.0)
  )

(defn annual-balance-update
  "Returns the annual balance update, taking into account the interest rate."
  [balance]
  (*' balance (bigdec(abs (interest-multiplier (interest-rate balance)))))
)

(defn amount-to-donate
  "Returns how much money to donate based on the balance and the tax-free percentage."
  [balance tax-free-percentage]
  (if (pos? balance) (int (/ (*' 2 tax-free-percentage balance) 100)) 0)
  )