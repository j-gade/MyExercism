using System.Globalization;

public static class HighSchoolSweethearts
{
    public static string DisplaySingleLine(string studentA, string studentB)
        => $"{studentA,29} ♡ {studentB,-29}";

    public static string DisplayBanner(string studentA, string studentB) =>
@"     ******       ******
   **      **   **      **
 **         ** **         **
**            *            **
**                         **
"+
$"**{studentA,11} +  {studentB,-10}**\n" +
@" **                       **
   **                   **
     **               **
       **           **
         **       **
           **   **
             ***
              *";

    public static string DisplayGermanExchangeStudents(string studentA
        , string studentB, DateTime start, float hours) =>
        string.Create(new CultureInfo("de-DE"), $"{studentA} and {studentB} have been dating since {start:d} - that's {hours:n2} hours");
}
