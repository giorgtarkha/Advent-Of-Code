import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.io.PrintWriter;
import java.io.FileNotFoundException;
import java.io.UnsupportedEncodingException;
import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

public class Problem2 {
	
	public static Map<String, String> memo = new HashMap<String, String>();
	
	static String getHash(String val, MessageDigest md) {
		byte[] hash = md.digest(val.getBytes());
		String hashString = "";
		for (int i = 0; i < hash.length; i++) {
			hashString += String.format("%02x", hash[i] & 0xff);
		}
		return hashString;
	}
	
	static String getStretchedHash(String val, MessageDigest md) {
		if (memo.containsKey(val)) {
			return memo.get(val);
		}
		String hash = getHash(val, md);
		for (int i = 0; i < 2016; i++) {
			hash = getHash(hash, md);
		}
		memo.put(val, hash);
		return hash;
	}
	
	static boolean isKey(String salt, int num, MessageDigest md) {
		String hashString = getStretchedHash(salt + num, md);
		char c = ' ';
		for (int i = 0; i < hashString.length() - 2; i++) {
			if (hashString.charAt(i) == hashString.charAt(i + 1) && hashString.charAt(i) == hashString.charAt(i + 2)) {
				c = hashString.charAt(i);
				break;
			}
		}	
		
		if (c == ' ') {
			return false;
		}
		
		for (int i = 1; i <= 1000; i++) {
			String nextHash = getStretchedHash(salt + (num + i), md);
			for (int j = 0; j < nextHash.length() - 4; j++) {
				if (nextHash.charAt(j) == nextHash.charAt(j + 1) && 
					nextHash.charAt(j) == nextHash.charAt(j + 2) &&
					nextHash.charAt(j) == nextHash.charAt(j + 3) &&
					nextHash.charAt(j) == nextHash.charAt(j + 4)) {
					if (nextHash.charAt(j) == c) {
						return true;
					}
				}
			}
			
		}
		
		return false;
	}
	
	public static void main(String[] args) {
		try {
			PrintWriter writer = new PrintWriter("Problem2.out", "UTF-8");
			MessageDigest md = MessageDigest.getInstance("MD5");
			String salt = "jlmsuwbz";
			int count = 0;
			for (int i = 0;;i++) {
				if (isKey(salt, i, md)) {
					count++;
				}
				if (count == 64) {
					writer.print(i);
					writer.close();
					break;
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
	
}