//
// TuyaSmartUser+WCSession.h
// TuyaSmartBaseKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import "TuyaSmartUser.h"

/**
 We don't link WatchConnectivity.framework because not all developers need this feature.
 If the SDKs links WatchConnectivity.framework and don't use this feature, your app might be reject when submit to Apple Store.
 So please link WatchConnectivity.framework manually and use it on demand.
 */
//#import <WatchConnectivity/WatchConnectivity.h>

@class WCSession, WCSessionUserInfoTransfer;

NS_ASSUME_NONNULL_BEGIN

extern NSString *const TuyaSmartUserWCSessionKey;

/// We don't link WatchConnectivity.framework because not all developers need this feature.
/// If the SDKs links WatchConnectivity.framework and don't use this feature, your app might be reject when submit to Apple Store.
/// So please link WatchConnectivity.framework manually and use it on demand.
@interface TuyaSmartUser (WCSession)

/// Sync TuyaSmartUser context to Apple Watch. When user login/logout/session expired on iPhone, please use this method to sync manually.
/// Example: [TuyaSmartUser.sharedInstance updateApplicationContext:session];
/// @param session Session.
/// @return Results of synchrony.
- (BOOL)updateApplicationContext:(WCSession *)session API_AVAILABLE(ios(9.0));

/// Receive TuyaSmartUser context from iPhone.
/// @param applicationContext Application Context.
- (void)didReceiveApplicationContext:(NSDictionary *)applicationContext API_AVAILABLE(watchos(2.0));

@end

NS_ASSUME_NONNULL_END
