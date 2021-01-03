import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.io.PrintWriter;
import java.io.FileNotFoundException;
import java.io.UnsupportedEncodingException;
import java.util.LinkedList; 
import java.util.Queue; 

public class Problem1 {
	
	static String getHash(String val, MessageDigest md) {
		byte[] hash = md.digest(val.getBytes());
		String hashString = "";
		for (int j = 0; j < hash.length; j++) {
			hashString += String.format("%02x", hash[j] & 0xff);
		}
		return hashString;
	}
	
	static boolean good(char c) {
		return c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f';
	}
	
	public static void main(String[] args) {
		try {
			PrintWriter writer = new PrintWriter("Problem1.out", "UTF-8");
			MessageDigest md = MessageDigest.getInstance("MD5");
			String key = "hhhxzeay";
			Queue<Pair> q = new LinkedList<Pair>();
			q.add(new Pair(0, 0, ""));
			while (q.size() > 0) {
				Pair current = q.remove();
				if (current.r == 3 && current.c == 3) {
					writer.print(current.path);
					writer.close();
					return;
				}
				String hash = getHash(key + current.path, md);
				if (good(hash.charAt(0)) && current.r - 1 >= 0) {
					q.add(new Pair(current.r - 1, current.c, current.path + 'U'));
				}
				if (good(hash.charAt(1)) && current.r + 1 < 4) {
					q.add(new Pair(current.r + 1, current.c, current.path + 'D'));
				}
				if (good(hash.charAt(2)) && current.c - 1 >= 0) {
					q.add(new Pair(current.r, current.c - 1, current.path + 'L'));
				}
				if (good(hash.charAt(3)) && current.c + 1 < 4) {
					q.add(new Pair(current.r, current.c + 1, current.path + 'R'));
				}
			}
		} catch (NoSuchAlgorithmException ex) {
			System.err.println("Couldn't find MD5 algorithm");
		} catch (FileNotFoundException ex) {
			System.err.println("Couldn't find file");
		} catch (UnsupportedEncodingException ex) {
			System.err.println("Unsuported encoding");
		}
	}
	
	static class Pair {
		
		public int r;
		
		public int c;
		
		public String path;
		
		public Pair(int r, int c, String path) {
			this.r = r;
			this.c = c;
			this.path = path;
		}
		
	}
	
}