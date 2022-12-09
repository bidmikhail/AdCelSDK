#import <Foundation/Foundation.h>
int main(int argc, const char *argv[]){printf("%s", [[@"/Users/misha/Documents/mobile-ios/AdToAppSDK-iOS/NewAdToApp" stringByAppendingPathComponent:[NSString stringWithUTF8String:argv[1]]]stringByResolvingSymlinksInPath].UTF8String);return 0;}
