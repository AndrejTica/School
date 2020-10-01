import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.CornerRadii;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.CheckBox;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.VBox;
import javafx.scene.media.AudioClip;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontPosture;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;

import java.awt.Insets;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.jar.JarException;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import javazoom.jl.decoder.JavaLayerException;
import javazoom.jl.player.Player;

public class Main extends Application {
	Button button1;
	Stage window;
	Scene scene1, scene2, scene3, scene4, scene5;

	ImageView image = new ImageView(new Image(getClass().getResourceAsStream("/pics/hat.JPG")));
	ImageView image2 = new ImageView(new Image(getClass().getResourceAsStream("/pics/edit.png")));
	ImageView image3 = new ImageView(new Image(getClass().getResourceAsStream("/pics/card2.jpg")));
	ImageView image4 = new ImageView(new Image(getClass().getResourceAsStream("/pics/removekebab.JPG")));

	public static void main(String[] args) {

		launch(args);
		
	}

	public void start(Stage primaryStage) throws Exception {
		
		window = primaryStage;
		
		// Button 1
		Label label1 = new Label("Hello world! I'm Java the magician.");
		Button button1 = new Button("Press to start trick");
		button1.setOnAction(e -> window.setScene(scene2));
		label1.setStyle("-fx-color: red");
		label1.setFont(Font.font("Cambria", 32));
		// Layout 1 - children laid out in vertical column
		StackPane layout1 = new StackPane();
		layout1.getChildren();
		layout1.setStyle("-fx-background-color: transparent;");
		scene1 = new Scene(layout1, 720, 700, Color.WHITE);
		layout1.getChildren().add(image);
		button1.setTranslateY(300);
		layout1.getChildren().add(button1);
		layout1.getChildren().add(label1);
		label1.setTranslateY(-300);
		 
		
		// Display scene 1 first
		window.setScene(scene1);
		window.setTitle("Java the magician");
		window.show();

		// Button 2
		Button button2 = new Button("Next");
		button2.setOnAction(e -> window.setScene(scene3));

		// Layout 2
		Label label2 = new Label("First, think of a number between 5 and 12.");
		StackPane layout2 = new StackPane();
		scene2 = new Scene(layout2, 720, 700);
		layout2.getChildren().add(button2);
		label2.setStyle("-fx-color: red");
		label2.setFont(Font.font("Cambria", 32));
		button2.setTranslateY(300);
		layout2.getChildren().add(label2);
		

		// Button 3
		Button button3 = new Button("Next");
		button3.setOnAction(e -> window.setScene(scene4));

		// Layout 3
		Label label3 = new Label("-Put your FInger on START and move your finger following the arrows as you count to your number." + "\n" +"-Leave your Finger wherever you stop." +"\n" +"-Now go backwards around the circle as you count again to your number.");
		StackPane layout3 = new StackPane();
		scene3 = new Scene(layout3, 720, 700, Color.WHITE);
		layout3.setStyle("-fx-background-color: transparent;");
		layout3.getChildren().add(button3);
		Text t = new Text (100, 200, "Remember the card you end up stopping on." +"\t"+ "Now click next below to see my prediction");
		button3.setTranslateY(300);
		
		label3.setStyle("-fx-color: red");
		label3.setFont(Font.font("Cambria", 13));
		t.setStyle("-fx-color: red");
		t.setFont(Font.font("Cambria", 15));
		
		layout3.getChildren().add(image2);
		layout3.getChildren().add(label3);
		label3.setTranslateY(-300);
		layout3.getChildren().add(t);
		t.setTranslateY(220);
		image2.setTranslateY(-30);
		
		// Button 4
		Button button4 = new Button("Next");
		button4.setOnAction(e -> window.setScene(scene5));

		// Layout 4
		Label label4 = new Label("The card you're thinking of is...");
		StackPane layout4 = new StackPane();
		scene4 = new Scene(layout4, 720, 700);
		
		layout4.getChildren().add(button4);
		label4.setStyle("-fx-color: red");
		label4.setFont(Font.font("Cambria", 32));
		button4.setTranslateY(300);
		layout4.getChildren().add(label4);
		
		// Button 5
				Button button5 = new Button("Applause");
				button5.setOnAction(e -> window.setScene(scene5));
				
		//Layout5
		Label label5 = new Label("Did I fool ya? :)");
		StackPane layout5 = new StackPane();
		scene5 = new Scene(layout5, 720, 700);
		layout5.getChildren().add(image3);
		layout5.getChildren().add(button5);
		label4.setStyle("-fx-color: red");
		label5.setFont(Font.font("Cambria", 20));
		button5.setTranslateY(300);
		layout5.getChildren().add(label5);
		label5.setTranslateY(250);


		// Button close
				
				button5.setOnAction(e -> closeProgram());
		
				new Thread() {

			@Override
			public void run() {

				Audio a = new Audio();
				a.audio();
			}
		}.start();

	}
private void closeProgram() {
	window.close();
}

}
