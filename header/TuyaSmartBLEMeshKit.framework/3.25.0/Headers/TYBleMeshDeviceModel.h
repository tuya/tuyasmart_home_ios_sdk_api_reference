//
// TYBleMeshDeviceModel.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import <TYBluetooth/TYBluetooth.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief The ble mesh device model when bluetooth scan some peripheral.
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

/// The device mac.
@property (nonatomic, assign) uint32_t mac;

/// THe device uuid.
@property (nonatomic, strong) NSString *uuid;

/// The device type.  Device size class.
@property (nonatomic, assign) uint32_t type;

/// Fusion expansion information
@property (nonatomic, strong) NSString *vendorInfo;

@end

NS_ASSUME_NONNULL_END
