using System;
using System.Collections.Generic;

public static class Languages
{
    public static List<string> NewList() => new List<string>();

    public static List<string> GetExistingLanguages()
    {
        var list = new string[] {"C#", "Clojure", "Elm"};
        return new List<string>(list);
    }

    public static List<string> AddLanguage(List<string> languages, string language)
    {
        languages.Add(language);
        return languages;
    }

    public static int CountLanguages(List<string> languages) => languages.Count;

    public static bool HasLanguage(List<string> languages, string language) => languages.Contains(language);
    
    public static List<string> ReverseList(List<string> languages)
    {
        languages.Reverse();
        return languages;
    }

    public static bool IsExciting(List<string> languages)
    {
        if (languages.Count > 0 && languages[0] == "C#")
            return true;
        if (languages.Count == 2 || languages.Count == 3)
        {
            if (languages[1] == "C#")
                return true;
        }
        return false;
    }

    public static List<string> RemoveLanguage(List<string> languages, string language)
    {
        languages.Remove(language);
        return languages;
    }

    public static bool IsUnique(List<string> languages)
    {
        for (var i = 0; i < languages.Count; i++)
        {
            for (var j = i+1; j < languages.Count; j++)
            {
                if (languages[i] == languages[j])
                    return false;
            }
        }
        return languages.Count > 0;
    }
}
