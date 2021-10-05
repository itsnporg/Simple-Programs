using System;
using System.Collections.Generic;
using System.Linq;

namespace MergingIntervalWithMergingDistance
{
    public class Program
    {
        public static List<Interval> MergeIntervalsWithMergingDistance(List<Interval> intervals, int mergingDistance)
        {
            List<Interval> result = new List<Interval>();
            if(intervals.Count == 0)
                return result;
            intervals.Sort((x, y) => x.start.CompareTo(y.start));
            Interval current = intervals[0];
            for(int i = 1; i < intervals.Count; i++)
            {
                if(intervals[i].start <= current.end + mergingDistance)
                {
                    current.end = Math.Max(current.end, intervals[i].end);
                }
                else
                {
                    result.Add(current);
                    current = intervals[i];
                }
            }
            result.Add(current);
            return result;
        }
    
        public static void Main()
        {
            int mergingDistance = 2;
            List<Interval> intervals = new List<Interval>();
            intervals.Add(new Interval(1, 3));
            intervals.Add(new Interval(2, 6));
            intervals.Add(new Interval(8, 10));
            intervals.Add(new Interval(15, 18));
            MergeIntervalsWithMergingDistance(intervals,mergingDistance);
        }
    }

    public class Interval
    {
        public int start;
        public int end;
        public Interval(int start, int end)
        {
            this.start = start;
            this.end = end;
        }
    }
}