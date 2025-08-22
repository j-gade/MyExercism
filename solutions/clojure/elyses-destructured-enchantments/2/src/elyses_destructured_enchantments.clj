(ns elyses-destructured-enchantments)

(defn first-card
  "Returns the first card from deck."
  [[card]]
    card)

(defn second-card
  "Returns the second card from deck."
  [[_ card]]
    card)

(defn swap-top-two-cards
  "Returns the deck with first two items reversed."
  [[first second & rest-deck]]
    (into [second first] rest-deck))

(defn discard-top-card
  "Returns a sequence containing the first card and
   a sequence of the remaining cards in the deck."
  [[top & rest-deck]]
    [top rest-deck])

(def face-cards
  ["jack" "queen" "king"])

(defn insert-face-cards
  "Returns the deck with face cards between its head and tail."
  [[top & rest-deck]]
    (if (nil? top)
      face-cards
      (into [] (concat [top] face-cards rest-deck))))
