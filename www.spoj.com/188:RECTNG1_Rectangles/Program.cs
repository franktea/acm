using System;
using System.Collections.Generic;

namespace RECTNG1_Rectangles
{
	class Edege
	{
		public int x1;
		public int x2;
		public int y1;
		public int y2;

		public Edege(int x1, int y1, int x2, int y2)
		{
			this.x1 = x1;
			this.y1 = y1;
			this.x2 = x2;
			this.y2 = y2;
		}

		public override bool Equals(object obj)
		{
			Edege eg2 = obj as Edege;
			return x1 == eg2.x1 && y1 == eg2.y1 && x2 == eg2.x2 && y2 == eg2.y2;
		}

		public override int GetHashCode()
		{
			return (x1 + y1) ^ (x2 + y2);
		}	
	}

	class RectAngle
	{
		public int x1;
		public int x2;
		public int y1;
		public int y2;
		public bool visited = false;
		public Edege[] Edeges;

		public RectAngle(int x1, int y1, int x2, int y2)
		{
			this.x1 = x1;
			this.y1 = y1;
			this.x2 = x2;
			this.y2 = y2;
            visited = false;
			Edeges = new Edege[] { new Edege (x1, y1, x1, y2),
				new Edege (x1, y2, x2, y2),
				new Edege (x2, y1, x2, y2),
				new Edege (x1, y1, x2, y1)
			};
		}
	}

	class MainClass
	{
        static void DFS(Dictionary<Edege, List<RectAngle> > dic, RectAngle ra)
        {
            ra.visited = true;
            foreach (Edege edege in ra.Edeges)
            {
                foreach (RectAngle rect_angle in dic[edege])
                {
                    if (!rect_angle.visited)
                    {
                        DFS(dic, rect_angle);
                    }
                }
            }
        }

		static int Count(Dictionary<Edege, List<RectAngle> > dic)
		{
            int result = 0;
            foreach (KeyValuePair<Edege, List<RectAngle> > kv in dic)
            {
                foreach (RectAngle ra in kv.Value)
                {
                    if (!ra.visited)
                    {
                        ++result;
                        DFS(dic, ra);
                    }
                }
            }
            return result;
		}
		
		public static void Main (string[] args)
		{
			int case_count = int.Parse (Console.ReadLine ());
            for(int cc = 0; cc < case_count; ++cc)
			{
                if (cc > 0)
                {
                    Console.ReadLine();
                }

				int rect_count = int.Parse (Console.ReadLine ());
                Dictionary<Edege, List<RectAngle> > dic = new Dictionary<Edege, List<RectAngle> > ();
				while (rect_count-- > 0) 
				{
					string[] values = Console.ReadLine ().Split (' ');
					RectAngle ra = new RectAngle (int.Parse (values [0]), int.Parse (values [1]), 
						int.Parse (values [2]), int.Parse (values [3]));
					foreach (Edege eg in ra.Edeges) 
					{
                        if (dic.ContainsKey(eg))
                        {
                            List<RectAngle> l = dic[eg];
                            l.Add(ra);
                        }
                        else
                        {
                            List<RectAngle> l = new List<RectAngle>();
                            l.Add(ra);
                            dic.Add(eg, l);
                        }
					}
				}
                Console.WriteLine(Count(dic));
			}
		}
	}
}
