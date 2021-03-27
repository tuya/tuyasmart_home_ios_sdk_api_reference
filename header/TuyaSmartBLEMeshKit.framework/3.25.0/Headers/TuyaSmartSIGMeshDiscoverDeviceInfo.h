//
// TuyaSmartSIGMeshDiscoverDeviceInfo.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import <TYBluetooth/TYBLEAgent.h>

/// sig mesh scan node type.
typedef NS_ENUM(NSUInteger, SIGMeshNodeProvisionType) {
    
    /// Unknow device.
    SIGMeshNodeUnknow,
    
    /// New device.
    SIGMeshNodeUnprovision,
    
    /// Provisiond device.
    SIGMeshNodeProvisioned,
    
    /// Already proxy, only need connect and control.
    SIGMeshNodeProxyed,
};

/// sig mesh node activator type.
typedef enum : NSUInteger {
    /// Standard distribution network.
    TYSIGMeshNodeActivatorTypeStandard = 0,
    
    /// Fast distribution network.
    TYSIGMeshNodeActivatorTypeQuick = 1 << 0,
} TYSIGMeshNodeActivatorType;

NS_ASSUME_NONNULL_BEGIN

#define kQuickVersion @"kQuickVersion"

/// @brief The ble mesh device model when bluetooth scan some peripheral.
@interface TuyaSmartSIGMeshDiscoverDeviceInfo : NSObject

/// The scan bluetooth peripheral.
@property (nonatomic, strong) TYBLEPeripheral *peripheral;

/// Node type.
@property (nonatomic, assign) SIGMeshNodeProvisionType provisionType;

/// Active network type.
@property (nonatomic, assign) TYSIGMeshNodeActivatorType activatorType;

/// The node mac.
@property (nonatomic, copy) NSString *mac;

/// The pcc for tuya node.
@property (nonatomic, copy) NSString *type;

/// The product id for tuya node.
@property (nonatomic, copy) NSString *productId;

/// For ota.
@property (nonatomic, copy) NSString *nodeId;

/// QuickSuccess: YES | NO , for extend.
@property (nonatomic, strong) NSDictionary *extendInfo;

@end

NS_ASSUME_NONNULL_END
