/*
* Demo: jdbc und mysql
* mysql-connectorXXXX.jar muss verwendet werden.
 

javac Is_uni_jdbc.java

java -cp mysql-connector-java-5.1.35-bin.jar:. Is_uni_jdbc

* 
*/

import java.sql.*;

public class Is_uni_jdbc {
	public static void main(String[] args) {
				
		try {
			String sDbDrv="com.mysql.jdbc.Driver";

			String sDbUrl="jdbc:mysql://localhost:3306/is_uni"; 
			String sUsr="is_uni";
			String sPwd="comein";
			String sTable="is_professoren";

			Connection conn;
			Statement stmt;
			ResultSet rslt;

			Class.forName( sDbDrv );

			conn = DriverManager.getConnection( sDbUrl, sUsr, sPwd );
			stmt = conn.createStatement();
			rslt = stmt.executeQuery( "select persnr,name from " + sTable );

			System.out.printf("%6s:%-15s\n", "PERSNR","NAME");
			while( rslt.next() ) {
				System.out.printf("%6d:%-15s\n", rslt.getInt(1),  rslt.getString(2));
			}
			conn.close();
		}
		catch( Exception e ) {
			e.printStackTrace(System.out);
		}
	}
}
