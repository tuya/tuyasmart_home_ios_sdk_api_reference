//
// TuyaSmartSIGMeshDiscoverDeviceInfo.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import <TYBluetooth/TYBLEAgent.h>

/// sig mesh scan node type.=====The type of Bluetooth mesh node to be scanned.
typedef NS_ENUM(NSUInteger, SIGMeshNodeProvisionType) {
    
    /// An unknown device.
    SIGMeshNodeUnknow,
    
    /// A new device.
    SIGMeshNodeUnprovision,
    
    /// A provisioned device.
    SIGMeshNodeProvisioned,
    
    /// Already proxy, only need connect and control.====A device that can be connected and controlled through a proxy.
    SIGMeshNodeProxyed,
};

/// sig mesh node activator type.====The activator type of the Bluetooth mesh node.
typedef enum : NSUInteger {
    /// Standard distribution network.=====Standard pairing.
    TYSIGMeshNodeActivatorTypeStandard = 0,
    
    /// Fast distribution network.======Fast pairing.
    TYSIGMeshNodeActivatorTypeQuick = 1 << 0,
} TYSIGMeshNodeActivatorType;

NS_ASSUME_NONNULL_BEGIN

#define kQuickVersion @"kQuickVersion"

/// @brief The ble mesh device model when bluetooth scan some peripheral.=====The Bluetooth LE mesh device model that is used to scan a Bluetooth peripheral.
@interface TuyaSmartSIGMeshDiscoverDeviceInfo : NSObject

/// The scan bluetooth peripheral.=====The bluetooth peripheral to be scanned.
@property (nonatomic, strong) TYBLEPeripheral *peripheral;

/// The node type.
@property (nonatomic, assign) SIGMeshNodeProvisionType provisionType;

/// Active network type.=====The activator type.
@property (nonatomic, assign) TYSIGMeshNodeActivatorType activatorType;

/// The node MAC.
@property (nonatomic, copy) NSString *mac;

/// The pcc for tuya node.=====The product category code (PCC) value of the `Powered by Tuya` device node.
@property (nonatomic, copy) NSString *type;

/// The product ID for tuya node.
@property (nonatomic, copy) NSString *productId;

/// Applies to OTA updates.
@property (nonatomic, copy) NSString *nodeId;

/// QuickSuccess: YES | NO , for extend.======Indicates whether quick pairing is successful. Valid values: `YES` and `NO`. This value is used as the extension information.
@property (nonatomic, strong) NSDictionary *extendInfo;

@end

NS_ASSUME_NONNULL_END
