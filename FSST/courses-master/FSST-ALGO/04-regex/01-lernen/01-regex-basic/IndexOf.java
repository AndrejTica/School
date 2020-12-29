/**
 * @author Anton Hofmann
 * @date 24.10.2012
 * @file IndexOf.java
 * @description Einfache Textsuche
 */

public class IndexOf {


	public static int indexOf(String text, String pattern, 
						int startIndex){
		int txtlen= text.length();
		int plen= pattern.length();
		boolean contains;

		for(int i=startIndex; i <= txtlen-plen; i++  ){
			contains=?????????;
			for (int j=0; j < plen && contains==true; j++){
				if (text.charAt(??????) != pattern.charAt(????)){
					contains=?????;
				}
			}
			?????????
		}

		???????????;
	}

	public static void main(String[] args) {

		System.out.println(indexOf("hofmann", "nn", 0));

		System.out.println(indexOf("hofmann", "na", 0));
	}
}

// Ausgabe:
// 5
//-1
