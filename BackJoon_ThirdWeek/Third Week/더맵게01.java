import java.util.*;
class Solution {
    public int solution(int[] scoville, int K) {
        PriorityQueue<Integer> q = new PriorityQueue<>();

        for(int i = 0; i < scoville.length; i++)
            q.add(scoville[i]);

        int count = 0;
        while(q.size() > 1 && q.peek() < K){
            int weakHot = q.poll();    //poll() 함수: 큐에서 객체를 꺼내서 반환
            int secondWeakHot = q.poll();

            int mixHot = weakHot + (secondWeakHot * 2);
            q.add(mixHot);
            count++;
        }

        if(q.size() <= 1 && q.peek() < K)
            count = -1;

        return count;
    }
}
