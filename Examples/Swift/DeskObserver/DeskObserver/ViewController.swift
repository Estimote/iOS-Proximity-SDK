//
// Please report any problems with this app template to contact@estimote.com
//


import UIKit
import EstimoteProximitySDK

class ViewController: UIViewController {
    
    @IBOutlet weak var blueberryDeskLabel: UILabel!
    @IBOutlet weak var mintDeskLabel: UILabel!
    @IBOutlet weak var venueLabel: UILabel!
    
    let blueberryColor = UIColor(red:  36/255.0, green:  24/255.0, blue:  93/255.0, alpha: 1.0)
    let mintColor = UIColor(red: 155/255.0, green: 186/255.0, blue: 160/255.0, alpha: 1.0)
    let venueColor = UIColor.darkGray
    
    var proximityObserver: EPXProximityObserver!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // ---- UI config ----
        
        // There are three labels with different text & border colors. 
        // They reverse text color and background color depending on proximity changes.
        
        let labels = [self.blueberryDeskLabel!, self.mintDeskLabel!, self.venueLabel!]
        for label in labels {
            label.backgroundColor = UIColor.white
            label.layer.borderWidth = 3.0
        }
        
        self.blueberryDeskLabel.layer.borderColor = self.blueberryColor.cgColor
        self.blueberryDeskLabel.textColor = self.blueberryColor
        
        self.mintDeskLabel.layer.borderColor = self.mintColor.cgColor
        self.mintDeskLabel.textColor = self.mintColor
        
        self.venueLabel.layer.borderColor = self.venueColor.cgColor
        self.venueLabel.textColor = self.venueColor
        
        
        // ---- Proximity config ----

        // TODO: put your App ID and App Token here
        // You can get them by adding your app on https://cloud.estimote.com/#/apps
        let credentials = EPXCloudCredentials(appID: <#your-app-id#>, appToken: <#your-app-token#>)
        
        // There's just a one Proximity Observer object used to configure reactions to proximity changes.
        // The configuration of a zone consists of defining a desired approximate range (0.5m or 1.5m in this example), 
        // attachment key, value pair ("desk" : "blueberry", "desk" : "mint" or "venue" : "office" in this example)
        // and a handler block called when a zone "enter" / "exit" / "change of beacons in range" happens.
        //
        // For more info on attachment-based beacon identification, check out the README in this repository
        // ( https://github.com/Estimote/iOS-Proximity-SDK/blob/master/README.md ).
        
        // TODO: The demo assumes proper settings configuration in Estimote Cloud. Make sure that:
        // - you have at least 2 beacons assigned to your Estimote Cloud account
        // - one of the beacons has a tag `{"attachment":{"desk":"blueberry","venue":"office"}}`
        // - another beacon has a tag `{"attachment":{"desk":"mint","venue":"office"}}`
        
        self.proximityObserver = EPXProximityObserver(credentials: credentials, errorBlock: { error in
            print("Ooops! \(error)")
        })
        
        let blueberryZone = EPXProximityZone(range: EPXProximityRange.custom(desiredMeanTriggerDistance: 0.5)!,
                                             attachmentKey: "desk",
                                             attachmentValue: "blueberry")
        blueberryZone.onEnterAction = { attachment in
            print("Enter blueberry (close range)")
            self.blueberryDeskLabel.backgroundColor = self.blueberryColor
            self.blueberryDeskLabel.textColor = UIColor.white
        }
        blueberryZone.onExitAction = { attachment in
            print("Exit blueberry (close range)")
            self.blueberryDeskLabel.backgroundColor = UIColor.white
            self.blueberryDeskLabel.textColor = self.blueberryColor
        }
        
        let mintZone = EPXProximityZone(range: EPXProximityRange.custom(desiredMeanTriggerDistance: 0.5)!,
                                        attachmentKey: "desk",
                                        attachmentValue: "mint")
        mintZone.onEnterAction = { attachment in
            print("Enter mint (close range)")
            self.mintDeskLabel.backgroundColor = self.mintColor
            self.mintDeskLabel.textColor = UIColor.white
        }
        mintZone.onExitAction = { attachment in
            print("Exit mint (close range)")
            self.mintDeskLabel.backgroundColor = UIColor.white
            self.mintDeskLabel.textColor = self.mintColor
        }
        
        let closeVenueZone = EPXProximityZone(range: EPXProximityRange.custom(desiredMeanTriggerDistance: 0.5)!,
                                              attachmentKey: "venue",
                                              attachmentValue: "office")
        closeVenueZone.onChangeAction = { attachmentsInside in
            print("Currently, there are \(attachmentsInside.count) attachments in close range:")
            print("\(attachmentsInside.map({ $0.json.description }).joined(separator: "\n"))")
            print("")
        }
        
        let midVenueZone = EPXProximityZone(range: EPXProximityRange.custom(desiredMeanTriggerDistance: 1.5)!,
                                            attachmentKey: "venue",
                                            attachmentValue: "office")
        midVenueZone.onEnterAction = { attachment in
            print("Enter venue (mid range)")
            self.venueLabel.backgroundColor = self.venueColor
            self.venueLabel.textColor = UIColor.white
        }
        midVenueZone.onExitAction = { attachment in
            print("Exit venue (mid range)")
            self.venueLabel.backgroundColor = UIColor.white
            self.venueLabel.textColor = self.venueColor
        }
        midVenueZone.onChangeAction = { attachmentsInside in
            print("Currently, there are \(attachmentsInside.count) attachments in mid range:")
            print("\(attachmentsInside.map({ $0.json.description }).joined(separator: "\n"))")
            print("")
        }
        
        self.proximityObserver.startObserving([mintZone, blueberryZone, closeVenueZone, midVenueZone])
    }
}

