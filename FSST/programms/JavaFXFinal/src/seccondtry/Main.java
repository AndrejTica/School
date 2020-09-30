package seccondtry;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

/**
 * Created by osama on 7/5/16.
 * the main class
 */
public class Main extends Application {
    static Stage stage;
    @Override
    public void start(Stage primaryStage) throws Exception {
        stage=primaryStage;
        //load the root node from fxml file
        Parent root= FXMLLoader.load(Main.class.getResource("scene_one.fxml"));
        stage.setScene(new Scene(root,400,400));
        stage.setTitle("Demo Basic");
        stage.show();
    }
    public static void ch(String sceneName) throws IOException{
        Parent root=FXMLLoader.load(Main.class.getResource(sceneName));
        stage.setScene(new Scene(root,400,400));

    }
public static void main(String[] args) {
		
		launch(args);
		
	}
}