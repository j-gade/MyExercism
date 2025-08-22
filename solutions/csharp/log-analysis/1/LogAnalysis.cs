using System;

public static class LogAnalysis 
{
    public static string SubstringAfter(this string log, string delim) => log[(log.IndexOf(delim) + delim.Length)..];

    public static string SubstringBetween(this string log, string lDelim, string rDelim) => log[(log.IndexOf(lDelim) + lDelim.Length)..log.IndexOf(rDelim)];
    
    public static string Message(this string log) => log.SubstringAfter(": ");

    public static string LogLevel(this string log) => log.SubstringBetween("[", "]");
}