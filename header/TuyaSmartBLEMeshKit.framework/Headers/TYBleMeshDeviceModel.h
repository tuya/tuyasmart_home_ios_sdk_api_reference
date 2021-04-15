//
// TYBleMeshDeviceModel.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import <TYBluetooth/TYBluetooth.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief The Bluetooth mesh device model that is used to scan for Bluetooth peripherals.
@interface TYBleMeshDeviceModel : NSObject

/// The device name.
@property (nonatomic, strong) NSString *name;

/// The device.
@property (nonatomic, strong) TYBLEPeripheral *device;

/// The device address.
@property (nonatomic, assign) uint32_t address;

/// The product ID.
@property (nonatomic, strong) NSString *productId;

/// The device version.
@property (nonatomic, strong) NSString *version;

/// The device MAC.
@property (nonatomic, assign) uint32_t mac;

/// THe device UUID.
@property (nonatomic, strong) NSString *uuid;

/// The device type. The device size class.
@property (nonatomic, assign) uint32_t type;

/// Fusion expansion information=====The vendor information.
@property (nonatomic, strong) NSString *vendorInfo;

@end

NS_ASSUME_NONNULL_END
