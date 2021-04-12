//
// TYGroupDevList.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmart_TuyaSmartGroupDevListModel
#define TuyaSmart_TuyaSmartGroupDevListModel

#import <Foundation/Foundation.h>

/// group device list information
@interface TuyaSmartGroupDevListModel : NSObject


/// The device ID.
@property(nonatomic,strong) NSString    *devId;

/// The device ID.
@property(nonatomic,strong) NSString    *gwId;

/// Is the device online.
@property(nonatomic,assign) BOOL        online;

/// Device icon URL.
@property(nonatomic,strong) NSString    *iconUrl;

/// The product ID.
@property(nonatomic,strong) NSString    *productId;

/// Is the device selected.
@property(nonatomic,assign) BOOL        checked;

/// The device name.
@property(nonatomic,strong) NSString    *name;

/// The device address.
@property(nonatomic,strong) NSString    *nodeId;


@end

#endif

