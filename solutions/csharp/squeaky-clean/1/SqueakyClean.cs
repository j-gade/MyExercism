using System;
using System.Text;

public static class Identifier
{
    public static string Clean(string identifier)
    {

        StringBuilder replacement = new StringBuilder();
        bool kebabCase = false;

        foreach (char c in identifier)
        {
            if (Char.IsBetween(c, 'α', 'ω'))
            {
                // Skip Greek lowercase letters
            } else if (c == '-')
            {
                kebabCase = true;
                // Skip dash
            } else if (Char.IsControl(c))
            {
                replacement.Append("CTRL");
                kebabCase = false;
            } else if (Char.IsWhiteSpace(c))
            {
                replacement.Append('_');
                kebabCase = false;
            } else if (!Char.IsLetter(c) && c != '_')
            {
                // Skip special characters, punctuation, and digits
                kebabCase = false;

            // At this point we should only have letters and underscores
            } else if (Char.IsLetter(c) && kebabCase)
            {
                replacement.Append(Char.ToUpper(c));
                kebabCase = false;
            } else {
                replacement.Append(c);
                kebabCase = false;
            }
        }
        return replacement.ToString();
    }
}
