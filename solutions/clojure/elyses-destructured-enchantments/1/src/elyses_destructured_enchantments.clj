(ns elyses-destructured-enchantments)

(defn first-card
  "Returns the first card from deck."
  [deck]
    (let [[x] deck] x))

(defn second-card
  "Returns the second card from deck."
  [deck]
    (let [[_ y] deck] y))

(defn swap-top-two-cards
  "Returns the deck with first two items reversed."
  [deck]
    (let [[x y & remaining] deck]
      (into [y x] remaining)))

(defn discard-top-card
  "Returns a sequence containing the first card and
   a sequence of the remaining cards in the deck."
  [deck]
    (let [[t :as all] deck]
      [t (next all)]))

(def face-cards
  ["jack" "queen" "king"])

(defn insert-face-cards
  "Returns the deck with face cards between its head and tail."
  [deck]
    (if (empty? deck) face-cards
    (let [[t :as all] deck]
      (into (into [t] face-cards) (next all)))))
