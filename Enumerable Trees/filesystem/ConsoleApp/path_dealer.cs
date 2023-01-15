namespace MatCom.Exam;

public static class path_dealer
{
    public static bool is_valid_path(string path)
    {
        if(!path.StartsWith("/"))
        {
            return false;
        }

        if (path.EndsWith("/") && path.Length > 1)
        {
            return false;
        }

        for (int i = 0; i < path.Length; i++)
        {
            if (path[i] == '/')
            {
                if (i+1 <= path.Length-1 && path[i+1] == '/' )
                {
                    return false;
                }
            }
        }
        return true;
    }    
}