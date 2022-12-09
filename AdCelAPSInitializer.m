//
//  AdCelAPSInitializer.m
//
//  Created by Mikhail Krasnorutskiy on 22/6/21.
//  Copyright © 2021 AdCel. All rights reserved.
//

#if __has_include(<DTBiOSSDK/DTBiOSSDK.h>)

#if __is_target_arch(arm64) || __is_target_arch(x86_64)

#import <DTBiOSSDK/DTBiOSSDK.h>
#import <UIKit/UIKit.h>

@interface AdCelAPSInitializer : NSObject
@end

@implementation AdCelAPSInitializer

+(void)load
{
    [[NSNotificationCenter defaultCenter]addObserver:self
                                            selector:@selector(onDidFinishLaunchingNotification:)
                                                name:UIApplicationDidFinishLaunchingNotification
                                              object:nil];
}

+(void)onDidFinishLaunchingNotification:(NSNotification*)nt
{
    [[NSNotificationCenter defaultCenter]removeObserver:self];
    [AdCelAPSInitializer.sharedInstance application:UIApplication.sharedApplication didFinishLaunchingWithOptions:nt.userInfo];
}

+(AdCelAPSInitializer*)sharedInstance
{
    static AdCelAPSInitializer* i = nil;
    if (!i)
    {
        i = [[AdCelAPSInitializer alloc]init];
    }
    
    return i;
}

static BOOL apsInitialized = NO;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [[NSNotificationCenter defaultCenter]addObserverForName:@"ADCEL_APS_APP_KEY_RECEIVED"
                                                     object:nil
                                                      queue:NSOperationQueue.mainQueue
                                                 usingBlock:^(NSNotification * _Nonnull note) {
                
        
        if (!apsInitialized)
        {
            NSString* appKey = [note object];
            [[DTBAds sharedInstance] setAppKey:appKey];
            [DTBAds sharedInstance].mraidPolicy = CUSTOM_MRAID;
            [DTBAds sharedInstance].mraidCustomVersions = @[@"1.0", @"2.0", @"3.0"];
            
            apsInitialized = YES;
        }
    }];
    
    return YES;
}

@end

#endif

#endif
