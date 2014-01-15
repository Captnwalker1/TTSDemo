//
//  ViewController.h
//  TTSDemo
//
//  Created by Chris Walker on 5/7/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VSSpeechSynthesizer.h"

@interface ViewController : UIViewController <UITextFieldDelegate>
{
    VSSpeechSynthesizer *speech;
}

@property (strong, nonatomic) IBOutlet UITextField *textfield;
@property (strong, nonatomic) IBOutlet UIButton *button;

-(IBAction)speak;

@end
