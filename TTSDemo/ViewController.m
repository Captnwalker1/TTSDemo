//
//  ViewController.m
//  TTSDemo
//
//  Created by Chris Walker on 5/7/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "ViewController.h"
#import "VSSpeechSynthesizer.h"

@interface ViewController ()

@end

@implementation ViewController

-(IBAction)speak {
    NSLog(@"trying to speak!");
    @try{
        //VSSpeechSynthesizer *speech = [[NSClassFromString(@"VSSpeechSynthesizer") alloc] init];
        sleep(1);
        //iOS7 changed the methods to add an error param
        if (floor(NSFoundationVersionNumber) > NSFoundationVersionNumber_iOS_6_1) {
            [speech startSpeakingString:self.textfield.text error:nil];
        } else
            [speech startSpeakingString:self.textfield.text];
    } 
    @catch (NSException *e) {
        NSLog(@"Exception: %@", e);
    }
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    speech = [[NSClassFromString(@"VSSpeechSynthesizer") alloc] init];
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone) {
        return (interfaceOrientation == UIInterfaceOrientationPortrait);
    } else {
        return YES;
    }
}

-(BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [textField resignFirstResponder];
    [self speak];
    return YES;
}

@end
