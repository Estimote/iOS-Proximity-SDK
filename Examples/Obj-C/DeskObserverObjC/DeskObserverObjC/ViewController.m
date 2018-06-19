//
// Please report any problems with this app template to contact@estimote.com
//


#import "ViewController.h"
@import EstimoteProximitySDK;

@interface ViewController ()

@property (weak, nonatomic) IBOutlet UILabel *blueberryDeskLabel;
@property (weak, nonatomic) IBOutlet UILabel *mintDeskLabel;
@property (weak, nonatomic) IBOutlet UILabel *venueLabel;

@property (nonatomic) UIColor *blueberryColor;
@property (nonatomic) UIColor *mintColor;
@property (nonatomic) UIColor *venueColor;

@property (nonatomic) EPXProximityObserver *proximityObserver;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.blueberryColor = [UIColor colorWithRed:36/255.0 green:24/255.0 blue:93/255.0 alpha:1.0];
    self.mintColor = [UIColor colorWithRed:155/255.0 green:186/255.0 blue:160/255.0 alpha:1.0];
    self.venueColor = [UIColor darkGrayColor];
    
    // ---- UI config ----
    
    // There are three labels with different text & border colors.
    // They reverse text color and background color depending on proximity changes.
    
    for (UILabel *label in @[self.blueberryDeskLabel, self.mintDeskLabel, self.venueLabel]) {
        label.backgroundColor = [UIColor whiteColor];
        label.layer.borderWidth = 3.0;
    }
    
    self.blueberryDeskLabel.layer.borderColor = self.blueberryColor.CGColor;
    self.blueberryDeskLabel.textColor = self.blueberryColor;
    
    self.mintDeskLabel.layer.borderColor = self.mintColor.CGColor;
    self.mintDeskLabel.textColor = self.mintColor;
    
    self.venueLabel.layer.borderColor = self.venueColor.CGColor;
    self.venueLabel.textColor = self.venueColor;
    
    // ---- Proximity config ----
    
    // TODO: put your App ID and App Token here
    // You can get them by adding your app on https://cloud.estimote.com/#/apps

    EPXCloudCredentials *credentials = [[EPXCloudCredentials alloc] initWithAppID:<#your-app-id#> appToken:<#your-app-token#>];
    
    // There's just a one Proximity Observer object used to configure reactions to proximity changes.
    // The configuration of a zone consists of defining a desired approximate range (0.5m or 1.5m in this example),
    // attachment key, value pair ("desk" : "blueberry", "desk" : "mint" or "venue" : "office" in this example)
    // and a handler block called when a zone "enter" / "exit" / "change of beacons in range" happens.
    //
    // For more info on attachment-based beacon identification, check out the README in this repository
    // ( https://github.com/Estimote/iOS-Proximity-SDK/blob/master/README.md ).
    
    // TODO: The demo assumes proper settings configuration in Estimote Cloud. Make sure that:
    // - you have at least 2 beacons assigned to your Estimote Cloud account
    // - one of the beacons has an attachment `{"desk":"blueberry","venue":"office"}`
    // - another beacon has an attachment `{"desk":"mint","venue":"office"}`
    
    self.proximityObserver = [[EPXProximityObserver alloc] initWithCredentials:credentials errorBlock:^(NSError * _Nonnull error) {
        NSLog(@"Ooops! %@", error);
    }];
    
    // Blueberry
    
    EPXProximityZone *blueberryZone = [[EPXProximityZone alloc] initWithRange:[EPXProximityRange customRangeWithDesiredMeanTriggerDistance:0.5]
                                                                          tag:@"blueberry"];
    blueberryZone.onEnterAction = ^(id<EPXProximityZoneContext> context) {
        NSLog(@"Enter blueberry (close range)");
        self.blueberryDeskLabel.backgroundColor = self.blueberryColor;
        self.blueberryDeskLabel.textColor = [UIColor whiteColor];
    };
    blueberryZone.onExitAction = ^(id<EPXProximityZoneContext> context) {
        NSLog(@"Exit blueberry (close range)");
        self.blueberryDeskLabel.backgroundColor = [UIColor whiteColor];
        self.blueberryDeskLabel.textColor = self.blueberryColor;
    };
    
    // Mint
    
    EPXProximityZone *mintZone = [[EPXProximityZone alloc] initWithRange:[EPXProximityRange customRangeWithDesiredMeanTriggerDistance:0.5]
                                                                     tag:@"mint"];
    mintZone.onEnterAction = ^(id<EPXProximityZoneContext> context) {
        NSLog(@"Enter mint (close range)");
        self.mintDeskLabel.backgroundColor = self.mintColor;
        self.mintDeskLabel.textColor = [UIColor whiteColor];
    };
    mintZone.onExitAction = ^(id<EPXProximityZoneContext> context) {
        NSLog(@"Exit mint (close range)");
        self.mintDeskLabel.backgroundColor = [UIColor whiteColor];
        self.mintDeskLabel.textColor = self.mintColor;
    };
    
    // Venue
    EPXProximityZone *closeVenueZone = [[EPXProximityZone alloc] initWithRange:[EPXProximityRange customRangeWithDesiredMeanTriggerDistance:0.5]
                                                                           tag:@"office"];
    closeVenueZone.onChangeAction = ^(NSSet<id<EPXProximityZoneContext>> *contextsInside) {
        NSLog(@"Currently, there are %@ attachments in close range: %@", @(contextsInside.count), contextsInside);
    };
    
    EPXProximityZone *midVenueZone = [[EPXProximityZone alloc] initWithRange:[EPXProximityRange customRangeWithDesiredMeanTriggerDistance:1.5]
                                                                         tag:@"office"];
    midVenueZone.onEnterAction = ^(id<EPXProximityZoneContext> context) {
        NSLog(@"Enter venue (mid range)");
        self.venueLabel.backgroundColor = self.venueColor;
        self.venueLabel.textColor = [UIColor whiteColor];
    };
    midVenueZone.onExitAction = ^(id<EPXProximityZoneContext> context) {
        NSLog(@"Exit venue (mid range)");
        self.venueLabel.backgroundColor = [UIColor whiteColor];
        self.venueLabel.textColor = self.venueColor;
    };
    midVenueZone.onChangeAction = ^(NSSet<id<EPXProximityZoneContext>> *contextsInside) {
        NSLog(@"Currently, there are %@ attachments in mid range: %@", @(contextsInside.count), contextsInside);
    };
    
    [self.proximityObserver startObservingZones:@[mintZone, blueberryZone, closeVenueZone, midVenueZone]];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
