package seccondtry;

import javafx.animation.FadeTransition;
import javafx.animation.Interpolator;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.control.Button;
import javafx.scene.layout.VBox;
import javafx.util.Duration;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

/**
 * Created by osama on 7/5/16.
 * The demo for youtube
 */
public class Controller implements Initializable {
    @FXML
    private VBox vBoxScene1;
    @FXML
    private VBox vBoxScene2;
    @FXML
    private Button button1;
    @FXML
    private Button button2;
    @Override
    public void initialize(URL location, ResourceBundle resources) {
        //trim the file locationt to get the filename
        String fileName=location.getFile().substring(location.getFile().lastIndexOf('/')+1,location.getFile().length());
        //check the file name and set animation according to that.
        if(fileName.equals("scene_one.fxml")){
            fadeTransition(vBoxScene1);
        }
        else if(fileName.equals("scene_two.fxml")){
            fadeTransition(vBoxScene2);
        }
    }

    public void ch(javafx.event.ActionEvent event) throws IOException {
        //get the button object on which user clicks and change scene acoording to that
        if(event.getSource().equals(button1)){
            try {
                Main.ch("scene_two.fxml");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        else if(event.getSource().equals(button2)){
            try {
                Main.ch("scene_one.fxml");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    /**
     *  Apply the Fade Transition to the node
     * @param e the node to which apply transition
     */
    private void fadeTransition(Node e){
        FadeTransition x=new FadeTransition(new Duration(2000),e);
        x.setFromValue(0);
        x.setToValue(100);
        x.setCycleCount(1);
        x.setInterpolator(Interpolator.LINEAR);
        x.play();
    }
}