import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;

public class Main {
	static int t;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		t = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= t; tc++) {
			int n = Integer.parseInt(br.readLine());
			String[] nums = new String[n];
			HashSet<String> set = new HashSet<>();
			boolean flag = false;
			for (int i = 0; i < n; i++) {
				nums[i] = br.readLine();
			}
			Arrays.sort(nums);
			for (int i = 0; i < n; i++) {
				if (flag)
					break;
				int length = nums[i].length();
				for (int j = 1; j <= length; j++) {
					if (set.contains(nums[i].substring(0, j))) {
						flag = true;
						break;
					}
				}
				set.add(nums[i]);
			}
			System.out.println(flag ? "NO" : "YES");
		}
	}
}
