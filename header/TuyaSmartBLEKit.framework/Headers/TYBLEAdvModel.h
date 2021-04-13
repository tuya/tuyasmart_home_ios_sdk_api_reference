//
// TYBLEAdvModel.h
// TuyaSmartBLEKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

/// The different type of BLE device.
typedef enum : NSUInteger {
    /// The unknown BLE device type.
    TYSmartBLETypeUnknow = 1,
    /// The old protocol BLE device type, which is not support security protocol.
    TYSmartBLETypeBLE,
    /// The old protocol BLE device type, which has a lower level of security.
    TYSmartBLETypeBLEPlus,
    /// The old protocol BLE dual-mode device type, which is not support security protocol.
    TYSmartBLETypeBLEWifi,
    /// The new protocol BLE device type, which has a high level of security.
    TYSmartBLETypeBLESecurity,
    /// The new protocol BLE dual-mode device type, which has a high level of security.
    TYSmartBLETypeBLEWifiSecurity,
    /// The new protocol BLE dual-mode device type, which has a high level of security and supports plug&play function.
    TYSmartBLETypeBLEWifiPlugPlay,
    /// The new protocol BLE and zigbee dual-mode device type, which has a high level of security.
    TYSmartBLETypeBLEZigbee,
    /// The new protocol BLE and LTE Cat.1 dual-mode device type, which has a high level of security.
    TYSmartBLETypeBLELTESecurity,
    /// beacon security
    TYSmartBLETypeBLEBeacon,
} TYSmartBLEType;

/// @brief TYBLEAdvModel provides model for developers to obtaine BLE device broadcast information.
///
/// All the device information is obtained from the Bluetooth device broadcast packet data.

/// The different types of BLE device type. See explanation below.
@interface TYBLEAdvModel : NSObject

/// The BLE device UUID.
@property (nonatomic, strong) NSString           *uuid;
/// The BLE device product Id.
@property (nonatomic, strong) NSString           *productId;
/// The BLE device mac address.
@property (nonatomic, strong) NSString           *mac;
/// The BLE device activation state.
@property (nonatomic, assign) BOOL               isActive;
/// The BLE device BLE device type.
@property (nonatomic, assign) TYSmartBLEType     bleType;
/// whether the BLE device support connect the router 5G band.
/// @note only available for `bleType` is `TYSmartBLETypeBLEWifi` or `TYSmartBLETypeBLEWifiSecurity`.
@property (nonatomic, assign) BOOL               isSupport5G;
/// whether the BLE device support product key.
@property (nonatomic, assign) BOOL               isProuductKey;
/// The BLE device device protocol version.
@property (nonatomic, assign) int                bleProtocolV;


@end
