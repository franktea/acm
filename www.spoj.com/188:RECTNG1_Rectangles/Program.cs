using System;
using System.Collections.Generic;

namespace RECTNG1_Rectangles
{
    enum Direction {right, up};

	class Point
	{
        public int x;
        public int y;
        public Direction d;

        public Point(int x, int y, Direction d)
		{
            this.x = x;
            this.y = y;
            this.d = d;
		}

		public override bool Equals(object obj)
		{
            Point p2 = obj as Point;
            return x == p2.x && y == p2.y && d == p2.d;
		}

		public override int GetHashCode()
		{
            return (x ^ y) + (int)d;
		}	
	}

	class RectAngle
	{
		public int x1;
		public int x2;
		public int y1;
		public int y2;
		public bool visited = false;
        public List<Point> points = new List<Point>();

		public RectAngle(int x1, int y1, int x2, int y2)
		{
			this.x1 = x1;
			this.y1 = y1;
			this.x2 = x2;
			this.y2 = y2;
            visited = false;
            for (int x = x1; x < x2; ++x)
                for (int y = y1; y < y2; ++y)
                {
                    points.Add(new Point(x, y, Direction.right));
                    points.Add(new Point(x, y, Direction.up));
                    points.Add(new Point(x, y + 1, Direction.right));
                    points.Add(new Point(x + 1, y, Direction.up));
                }
		}

//        public string StringContent()
//        {
//            return String.Format("{0}, {1}, {2}, {3}", x1, y1, x2, y2);
//        }
	}

	class MainClass
	{
        static void DFS(Dictionary<Point, List<RectAngle> > dic, RectAngle ra)
        {
            ra.visited = true;
            foreach (Point p in ra.points)
            {
                List<RectAngle> l = dic[p];
                foreach (RectAngle rect_angle in l)
                {
                    if (!rect_angle.visited)
                    {
                        //Console.WriteLine("now: {0}", rect_angle.StringContent());
                        DFS(dic, rect_angle);
                    }
                }
            }
        }

		static int Count(Dictionary<Point, List<RectAngle> > dic)
		{
            int result = 0;
            foreach (KeyValuePair<Point, List<RectAngle> > kv in dic)
            {
                foreach (RectAngle ra in kv.Value)
                {
                    if (!ra.visited)
                    {
                        //Console.WriteLine(ra.StringContent());
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
                Dictionary<Point, List<RectAngle> > dic = new Dictionary<Point, List<RectAngle> > ();
				while (rect_count-- > 0) 
				{
					string[] values = Console.ReadLine ().Split (' ');
					RectAngle ra = new RectAngle (int.Parse (values [0]), int.Parse (values [1]), 
						int.Parse (values [2]), int.Parse (values [3]));
                    foreach (Point p in ra.points) 
					{
                        if (dic.ContainsKey(p))
                        {
                            List<RectAngle> l = dic[p];
                            l.Add(ra);
                        }
                        else
                        {
                            List<RectAngle> l = new List<RectAngle>();
                            l.Add(ra);
                            dic.Add(p, l);
                        }
					}
				}
                Console.WriteLine(Count(dic));
			}
		}
	}
}
