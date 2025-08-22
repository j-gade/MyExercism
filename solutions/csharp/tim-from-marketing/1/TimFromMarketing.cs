using System;

static class Badge
{
    public static string Print(int? id, string name, string? department)
    {
        string idString = "";
        string deptString = "";

        if (id.HasValue)
        {
            idString = $"[{id.Value}] - ";
        }
        if (department != null)
        {
            deptString = $" - {department.ToUpper()}";
        } else {
            deptString = " - OWNER";
        }
        return idString + name + deptString;
    }
}
