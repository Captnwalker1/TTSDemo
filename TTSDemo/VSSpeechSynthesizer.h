//
//  VSSpeechSynthesizer.h
//  TTSDemo
//
//  Created by build on 5/7/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import  <foundation/foundation.h>

@interface VSSpeechSynthesizer : NSObject
{
    void *_speechJob;
    void *_keepAlive;
    //id <VSSpeechSynthesizerDelegate> _delegate;
    NSString *_voice;
    int _footprint;
    float _rate;
    float _pitch;
    float _volume;
    struct {
        unsigned int delegateStart:1;
        unsigned int delegateFinish:1;
        unsigned int delegateFinishWithPhonemesSpoken:1;
        unsigned int delegatePause:1;
        unsigned int delegateContinue:1;
        unsigned int delegateWillSpeak:1;
        unsigned int willUseInput:1;
    } _synthesizerFlags;
}

+ (id)availableVoices;
+ (id)availableVoicesForLanguageCode:(id)arg1;
+ (id)availableLanguageCodes;
+ (BOOL)isSystemSpeaking;
+ (void)_localeDidChange;
- (id)init;
- (id)initForInputFeedback;
- (void)dealloc;
- (void)setDelegate:(id)arg1;
- (BOOL)startSpeakingString:(id)arg1 error:(id*)arg2;
- (id)startSpeakingString:(id)arg1;
- (id)startSpeakingString:(id)arg1 toURL:(id)arg2;
- (id)startSpeakingString:(id)arg1 withLanguageCode:(id)arg2;
- (id)startSpeakingString:(id)arg1 attributedString:(id)arg2 toURL:(id)arg3 withLanguageCode:(id)arg4;
- (id)startSpeakingString:(id)arg1 toURL:(id)arg2 withLanguageCode:(id)arg3;
- (id)startSpeakingAttributedString:(id)arg1;
- (id)startSpeakingAttributedString:(id)arg1 toURL:(id)arg2;
- (id)startSpeakingAttributedString:(id)arg1 toURL:(id)arg2 withLanguageCode:(id)arg3;
- (id)stopSpeakingAtNextBoundary:(int)arg1;
- (id)stopSpeakingAtNextBoundary:(int)arg1 synchronously:(BOOL)arg2;
- (id)pauseSpeakingAtNextBoundary:(int)arg1;
- (id)pauseSpeakingAtNextBoundary:(int)arg1 synchronously:(BOOL)arg2;
- (id)continueSpeaking;
- (BOOL)isSpeaking;
- (id)speechString;
- (float)rate;
- (id)setRate:(float)arg1;
- (float)minimumRate;
- (float)maximumRate;
- (id)setPitch:(float)arg1;
- (float)pitch;
- (id)setVolume:(float)arg1;
- (float)volume;
- (void)setVoice:(id)arg1;
- (id)voice;
- (void)setFootprint:(int)arg1;
- (int)footprint;
- (void)setMaintainPersistentConnection:(BOOL)arg1;
//- (void)_handleSpeechStarted:(struct __VSSpeech *)arg1;
//- (void)_handleSpeechPaused:(struct __VSSpeech *)arg1;
//- (void)_handleSpeechContinued:(struct __VSSpeech *)arg1;
//- (void)_handleSpeech:(struct __VSSpeech *)arg1 completed:(BOOL)arg2 phonemesSpoken:(struct __CFString *)arg3 withError:(id)arg4;
//- (void)_handleSpeech:(struct __VSSpeech *)arg1 willSpeakMarkType:(int)arg2 inRange:(CDStruct_1ef3fb1f)arg3;

@end