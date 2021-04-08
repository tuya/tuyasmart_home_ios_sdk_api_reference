//
//  TYUtil.h
//  TuyaSmartBaseKit
//
//  Created by 高森 on 2018/6/12.
//

#import <Foundation/Foundation.h>

void tysdk_dispatch_async_on_default_global_thread(dispatch_block_t block);
void tysdk_dispatch_async_on_main_thread(dispatch_block_t block);
void tysdk_dispatch_sync_on_main_thread(dispatch_block_t block);

@interface TYSDKUtil : NSObject

#if TARGET_OS_IOS

+ (NSString *)tysdk_currentWifiSSID;

+ (NSString *)tysdk_currentWifiBSSID;

#endif

+ (uint32_t)tysdk_getIntValueByHex:(NSString *)str;

+ (NSString *)tysdk_getISOcountryCode;

+ (BOOL)tysdk_compareVesionWithDeviceVersion:(NSString *)deviceVersion appVersion:(NSString *)appVersion;

+ (NSData *)tysdk_xorEncodeData:(NSData *)sourceData keyData:(NSData *)keyData;

@end


extern NSString * const TYUtilHostAppExtensionString;
extern NSString * const TYUtilTodayWidgetExtensionString;
extern NSString * const TYUtilIntentExtensionString;
extern NSString * const TYUtilIntentUIExtensionString;
extern NSString * const TYUtilWatchKitExtensionString;

/**
 *  @category TYUtil(AppExtension)
 *  Checks the process in which the program runs (App/AppExtension/WatchKitExtension).
 */
@interface TYSDKUtil (AppSDKExtension)

+ (NSString *)tysdk_currentExtensionString;

+ (BOOL)tysdk_isHostApp;

+ (BOOL)tysdk_isAppExtension;

+ (BOOL)tysdk_isWatchKitExtension;

@end
