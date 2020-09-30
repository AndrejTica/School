import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.jar.JarException;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import javazoom.jl.decoder.JavaLayerException;
import javazoom.jl.player.Player;


public class Audio{
	

static void audio() {
	try {
		FileInputStream fileInputStream = new FileInputStream("te.mp3");
		Player player = new Player(fileInputStream);
		player.play();
		
	}catch(FileNotFoundException e) {
		e.printStackTrace();
	}catch(JavaLayerException e) {
		e.printStackTrace();
	}
}

}
