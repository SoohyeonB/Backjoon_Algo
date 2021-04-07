import java.util.*;

class Solution {
    public int[] solution(String[] operations) {
        int[] answer = new int[2];
        PriorityQueue<Integer> q1 = new PriorityQueue<>(); // 오름
        PriorityQueue<Integer> q2 = new PriorityQueue<>(Collections.reverseOrder()); // 내림
        
        // 문자열 처리
        for(String operation : operations){
            // 삽입
            if(operation.substring(0,1).equals("I")){
                int temp = Integer.valueOf(operation.substring(2));
                q1.add(temp);
                q2.add(temp);
            }
            // 최대값 삭제
            else if(operation.equals("D 1")){
                // 진행 불가 시
                if(q2.isEmpty()){
                    continue;
                }
                // 삭제
                int max = q2.peek();
                q1.remove(max);
                q2.remove(max);
            }
            
            // 최소값 삭제
            else if(operation.equals("D -1") ){
                // 진행 불가 시
                if(q1.isEmpty()){
                    continue;
                }
                // 삭제
                int min = q1.peek();
                q1.remove(min);
                q2.remove(min);
            }
        }
        
        // 값이 있을 경우
        if(!q1.isEmpty()){
            answer[0] = q2.peek(); // 최대
            answer[1] = q1.peek(); // 최소
        }
        
        return answer;
    }
}
