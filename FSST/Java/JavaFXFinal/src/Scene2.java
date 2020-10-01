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
public class Scene2 extends Application {
    static Stage stage;
    @Override
    public void start(Stage primaryStage) throws Exception {
        stage=primaryStage;
        //load the root node from fxml file
        Parent parent= FXMLLoader.load(Main.class.getResource("Scene0.fxml"));
        stage.setScene(new Scene(parent,400,400));
        stage.setTitle("Demo Basic");
        stage.show();
    }
    public static void changeScene (String sceneName) throws IOException{
        Parent parent=FXMLLoader.load(Main.class.getResource(sceneName));
        stage.setScene(new Scene(parent,400,400));

    }
}


