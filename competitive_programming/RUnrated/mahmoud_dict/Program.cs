namespace mahmoud_dict
{
    public class DisjointSets
    {
        private readonly int[] parent;
        private readonly int[] size;
        public DisjointSets(int N)
        {
            parent = new int[N];
            Array.Fill(parent, -1);
            size = new int[N];
        }
        public void Make_set(int i)
        {
            parent[i] = i;
            size[i] = 1;
        }
        public int Find_set(int a)
        {
            if (parent[a] == -1)
            {
                return -1;
            }
            if (parent[a] == a)
            {
                return a;
            }
            return parent[a] = Find_set(parent[a]);
        }
        public (int, int) Union(int a, int b) // (parent, not parent)
        {
            if (a == -1)
            {
                return (b, a);
            }
            if (b == -1)
            {
                return (a, b);
            }
            var l = Find_set(a);
            var r = Find_set(b);
            if (l == r)
            {
                return (l, r);
            }
            if (size[l] < size[r])
            {
                parent[l] = r;
                size[r] += size[l];
                size[l] = 0;
                return (r, l);
            }
            else
            {
                parent[r] = l;
                size[l] += size[r];
                size[r] = 0;
                return (l, r);
            }
        }
    }

    public class Test
    {
        public static void Main()
        {
            string[] numeros = Console.ReadLine().Split();
            int number_words = int.Parse(numeros[0]);
            DisjointSets relations = new(number_words);
            DisjointSets inside_relations = new(number_words);
            Dictionary<int, (int, int)> map = new();
            string[] words = Console.ReadLine().Split();
            Dictionary<string, int> indexes = new();
            for (int i = 0; i < words.Length; i++)
            {
                relations.Make_set(i);
                indexes[words[i]] = i;
                map[i] = (-1, -1);
            }
            int number_relations = int.Parse(numeros[1]);
            string[] answers = new string[number_relations];
            while (number_relations > 0)
            {
                string[] line = Console.ReadLine().Split();
                var type_relation = int.Parse(line[0]);
                var word1 = indexes[line[1]];
                var word2 = indexes[line[2]];
                var parent1 = relations.Find_set(word1);
                var parent2 = relations.Find_set(word2);

                if (parent1 == parent2)
                {
                    /*
                    they are related
                    */

                    if (word1 != parent1 && word2 != parent2)
                    {
                        if (inside_relations.Find_set(word1) == inside_relations.Find_set(word2))
                        {
                            /*
                            they are friends.
                            */
                            if (type_relation == 1)
                            {
                                answers[^number_relations] = "YES";
                            }
                            else
                            {
                                answers[^number_relations] = "NO";
                            }
                        }
                        else
                        {
                            if (type_relation == 1)
                            {
                                answers[^number_relations] = "NO";
                            }
                            else
                            {
                                answers[^number_relations] = "YES";
                            }
                        }
                    }

                    else if (word1 != parent1)
                    {
                        /*
                        word2 is a root.
                        */
                        if (type_relation == 1 && inside_relations.Find_set(word1) == map[word2].Item1)
                        {
                            answers[^number_relations] = "YES";
                        }
                        else if (type_relation == 2 && inside_relations.Find_set(word1) == map[word2].Item2)
                        {
                            answers[^number_relations] = "YES";
                        }
                        else
                        {
                            answers[^number_relations] = "NO";
                        }

                    }
                    else
                    {
                        /*
                        word1 is a root.
                        */
                        if (type_relation == 1 && inside_relations.Find_set(word2) == map[word1].Item1)
                        {
                            answers[^number_relations] = "YES";
                        }
                        else if (type_relation == 2 && inside_relations.Find_set(word2) == map[word1].Item2)
                        {
                            answers[^number_relations] = "YES";
                        }
                        else
                        {
                            answers[^number_relations] = "NO";
                        }
                    }
                }
                else
                {
                    /*
                    because parent are different this means that we have to join two components.
                    */

                    /*
                    first step is to find the relation that should be between the parents.
                    */

                    /*
                    once I know the relations between the parents.
                    */
                    if (word1 != parent1)
                    {
                        if (inside_relations.Find_set(word1) == map[parent1].Item2)
                        {
                            type_relation = type_relation == 1 ? 2 : 1;
                        }
                    }
                    if (word2 != parent2)
                    {
                        if (inside_relations.Find_set(word2) == map[parent2].Item2)
                        {
                            type_relation = type_relation == 1 ? 2 : 1;
                        }
                    }
                    var root = relations.Union(parent1, parent2);
                    if (type_relation == 1)
                    {
                        inside_relations.Make_set(root.Item2);
                        var friend = inside_relations.Union(
                                    root.Item2, map[root.Item1].Item1).Item1;
                        friend = inside_relations.Union(friend, map[root.Item2].Item1).Item1;

                        var enemy = inside_relations.Union(
                                    map[root.Item1].Item2,
                                    map[root.Item2].Item2).Item1;
                        map[root.Item1] = (friend, enemy);
                    }
                    if (type_relation == 2)
                    {
                        inside_relations.Make_set(root.Item2);
                        var enemy = inside_relations.Union(map[root.Item1].Item2, root.Item2).Item1;
                        enemy = inside_relations.Union(enemy, map[root.Item2].Item1).Item1;
                        var friend = inside_relations.Union(map[root.Item1].Item1, map[root.Item2].Item2).Item1;
                        map[root.Item1] = (friend, enemy);
                    }
                    answers[^number_relations] = "YES";
                }
                number_relations--;
            }
            foreach (var item in answers)
            {
                Console.WriteLine(item);
            }

            int number_queries = int.Parse(numeros[2]);
            int[] answers_queries = new int[number_queries];
            while (number_queries > 0)
            {
                string[] line = Console.ReadLine().Split();
                var word1 = indexes[line[0]];
                var word2 = indexes[line[1]];
                var parent1 = relations.Find_set(word1);
                var parent2 = relations.Find_set(word2);

                if (parent1 == parent2)
                {
                    /*
                    they are related
                    */

                    if (word1 != parent1 && word2 != parent2)
                    {
                        if (inside_relations.Find_set(word1) == inside_relations.Find_set(word2))
                        {
                            answers_queries[^number_queries] = 1;
                        }
                        else
                        {
                            answers_queries[^number_queries] = 2;
                        }
                    }
                    else if (word1 != parent1)
                    {
                        /*
                        word2 is a root.
                        */
                        if (inside_relations.Find_set(word1) == map[word2].Item1)
                        {
                            answers_queries[^number_queries] = 1;
                        }
                        else
                        {
                            answers_queries[^number_queries] = 2;
                        }
                    }
                    else
                    {
                        /*
                        word1 is a root.
                        */
                        if (inside_relations.Find_set(word2) == map[word1].Item1)
                        {
                            answers_queries[^number_queries] = 1;
                        }
                        else
                        {
                            answers_queries[^number_queries] = 2;
                        }
                    }
                }
                else
                {
                    answers_queries[^number_queries] = 3;
                }
                number_queries--;
            }
            foreach (var item in answers_queries)
            {
                Console.WriteLine(item);
            }
        }
    }
}