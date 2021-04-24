//
//  TYSDKLocalNetworkManager.h
//  TuyaSmartUtil
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(int, TYSDKLocalNetworkStatus) {
    // The local network is not connected (the Wi-Fi adapter cannot get an IP address).
    kTYSDKLocalNetworkStatusNotConnected,
    
    // The user has explicitly denied authorization for this application, or not yet made a choice.
    kTYSDKLocalNetworkStatusNotDeterminedOrDenied,
    
    // The user has granted permissions to use the local network only when your app is being used.
    kTYSDKLocalNetworkStatusStatusAuthorized,
};

API_AVAILABLE(ios(14.0))
@interface TYSDKLocalNetworkManager : NSObject

+ (instancetype)manager;

/**
    Returns the IP address of the local network (beta)
 */
- (NSString *)localIPAddress;

/**
    Requests permissions on the local network (beta)
 
    If you call this method when a Wi-Fi network is connected, a process is started to request permissions on the local network from the user. The authorization prompt will appear only once until the app is uninstalled.
    Currently, you cannot get an authorization change callback for this request.
 */
- (void)requestAuthorization;


/**
    Returns the current authorization status of the specified application (beta).
 */
- (void)authorizationStatus:(void (^)(TYSDKLocalNetworkStatus status))callback;

@end
