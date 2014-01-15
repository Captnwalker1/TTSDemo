//
//  VSSpeechSynthesizer.m
//  UKAssessment
//
//  Created by Chris Walker on 12/14/12.
//
//

#import "VSSpeechSynthesizer.h"

#if TARGET_IPHONE_SIMULATOR

@implementation VSSpeechSynthesizer
+ (id)availableLanguageCodes {
    return nil;
}
+ (BOOL)isSystemSpeaking {
    return NO;
}

-(NSString *)selectVoiceForPhrase:(NSString *)phrase {
    NSDictionary *keywordToVoice = @{
    @"failures!" : @"Bad",
    @"failure!" : @"Bruce",
    @"FAIL" : @"Agnes"
    };
    NSString *keyword = nil;
    for (keyword in [keywordToVoice allKeys]) {
        BOOL found = NSNotFound != [phrase rangeOfString:keyword].location;
        if (found) {
            break;
        }
    }
    return keyword ? [keywordToVoice objectForKey:keyword] : @"Vicki -r 150";
}

- (id)startSpeakingString:(id)what {
    NSString *voice = [self selectVoiceForPhrase:what];
    NSString *command = [NSString stringWithFormat:@"say -v %@ %@", voice, what];
    system([command cStringUsingEncoding:NSASCIIStringEncoding]);
    NSLog(@"%@", what);
    return nil;
}
- (id)startSpeakingString:(id)string toURL:(id)url {
    return nil;
}
- (id)startSpeakingString:(id)string toURL:(id)url withLanguageCode:(id)code {
    return nil;
}
- (float)rate {
    return 1;
}
- (id)setRate:(float)rate {
    return nil;
}
- (float)pitch {
    return 0.5;
}
- (id)setPitch:(float)pitch {
    return nil;
}
- (float)volume {
    return 0.8;
}
- (id)setVolume:(float)volume {
    return nil;
}
@end
#endif