public static class Identifier
{
    
    public static string Clean(string identifier)
    {
        var cleaned = new System.Text.StringBuilder();
        var kebabCase = false;
        
        foreach (var c in identifier)
        {
            cleaned.Append(c switch {
                _ when char.IsBetween(c, 'α', 'ω') => default,
                _ when char.IsWhiteSpace(c) => '_',
                _ when char.IsControl(c) => "CTRL",
                _ when kebabCase && char.IsLetter(c) => char.ToUpperInvariant(c),
                _ when char.IsLetter(c) => c,
                _ => default,
            });
            kebabCase = c.Equals('-');
        }
        return cleaned.ToString();
    }
}
