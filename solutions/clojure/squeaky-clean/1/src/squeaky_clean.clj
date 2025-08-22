(ns squeaky-clean
  (:require [clojure.string :as str]))

(defn replace-spaces-with-underscores
  "Replace any spaces encountered with underscores"
  [s]
  (str/replace s " " "_")
  )

(defn replace-ctrl-with-CTRL
  "Replace control characters with the string CTRL"
  [s]
  (str/escape s #(if (Character/isISOControl %) "CTRL" %)
  )
)
(defn capitalize
  "Capitalize the string without converting to lower case"
  [s]
  (str/replace s #"^." #(str/upper-case %))
  )

(defn convert-kebab-to-camel
  "Convert kebab-case to camelCase"
  [s]
  (if (str/includes? s "-")
    (let [split (str/split s #"-")]
      (str/join [(first split) (capitalize (second split)) (nthnext split 3)]))
    s)
  )

(defn omit-chars-not-letters
  "Remove characters that are not letters or underscores"
  [s]
  (str/escape s #(if (not (or (Character/isLetter %) (= % \_))) ""))
  )

(defn remove-greek-letters
  "Remove greek letters"
  [s]
  (str/replace s #"[\u03b1-\u03c9]" "")
  )

(defn clean
  "TODO: add docstring"
  [s]
  (omit-chars-not-letters
    (replace-ctrl-with-CTRL
      (convert-kebab-to-camel
        (replace-spaces-with-underscores
          (remove-greek-letters s)
        )
      )
    )
  )
)
