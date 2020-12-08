import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.io.PrintWriter;
import java.io.FileNotFoundException;
import java.io.UnsupportedEncodingException;

public class Problem2 {
	
	public static void main(String[] args) {
		try {
			PrintWriter writer = new PrintWriter("Problem2.out", "UTF-8");
			MessageDigest md = MessageDigest.getInstance("MD5");
			String key = "wtnhxymk";
			char[] password = new char[8];
			int count = 0;
			for (int i = 1;;i ++) {
				String currentKey = key + i;
				byte[] hash = md.digest(currentKey.getBytes());
				String hashString = "";
				for (int j = 0; j < hash.length; j++) {
					hashString += String.format("%02x", hash[j] & 0xff);
				}
				for (int j = 0; j < 6; j++) {
					if (j == 5) {
						if (hashString.charAt(5) >= '0' && hashString.charAt(5) <= '7' && password[hashString.charAt(5) - '0'] == 0x00) {
							password[hashString.charAt(5) - '0'] = hashString.charAt(6);
							count++;
						}
						if (count == 8) {
							writer.print(String.valueOf(password));
							writer.close();
							return;
						}
					} else {
						if (hashString.charAt(j) != '0') {
							break;
						}
					}
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