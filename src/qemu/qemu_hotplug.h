/*
 * qemu_hotplug.h: QEMU device hotplug management
 *
 * Copyright (C) 2006-2007, 2009-2012 Red Hat, Inc.
 * Copyright (C) 2006 Daniel P. Berrange
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * Author: Daniel P. Berrange <berrange@redhat.com>
 */

#ifndef __QEMU_HOTPLUG_H__
# define __QEMU_HOTPLUG_H__

# include "qemu_conf.h"
# include "qemu_domain.h"
# include "domain_conf.h"

int qemuDomainChangeEjectableMedia(virQEMUDriverPtr driver,
                                   virDomainObjPtr vm,
                                   virDomainDiskDefPtr disk,
                                   virDomainDiskDefPtr orig_disk,
                                   bool force);
int qemuDomainCheckEjectableMedia(virQEMUDriverPtr driver,
                                  virDomainObjPtr vm,
                                  enum qemuDomainAsyncJob asyncJob);
int qemuDomainAttachVirtioDiskDevice(virConnectPtr conn,
                                     virQEMUDriverPtr driver,
                                     virDomainObjPtr vm,
                                     virDomainDiskDefPtr disk);
int qemuDomainAttachPciControllerDevice(virQEMUDriverPtr driver,
                                        virDomainObjPtr vm,
                                        virDomainControllerDefPtr controller);
int qemuDomainAttachSCSIDisk(virConnectPtr conn,
                             virQEMUDriverPtr driver,
                             virDomainObjPtr vm,
                             virDomainDiskDefPtr disk);
int qemuDomainAttachUsbMassstorageDevice(virConnectPtr conn,
                                         virQEMUDriverPtr driver,
                                         virDomainObjPtr vm,
                                         virDomainDiskDefPtr disk);
int qemuDomainAttachNetDevice(virConnectPtr conn,
                              virQEMUDriverPtr driver,
                              virDomainObjPtr vm,
                              virDomainNetDefPtr net);
int qemuDomainAttachHostPciDevice(virQEMUDriverPtr driver,
                                  virDomainObjPtr vm,
                                  virDomainHostdevDefPtr hostdev);
int qemuDomainAttachHostUsbDevice(virQEMUDriverPtr driver,
                                  virDomainObjPtr vm,
                                  virDomainHostdevDefPtr hostdev);
int qemuDomainAttachRedirdevDevice(virQEMUDriverPtr driver,
                                   virDomainObjPtr vm,
                                   virDomainRedirdevDefPtr hostdev);
int qemuDomainAttachHostDevice(virQEMUDriverPtr driver,
                               virDomainObjPtr vm,
                               virDomainHostdevDefPtr hostdev);
int qemuDomainChangeGraphics(virQEMUDriverPtr driver,
                             virDomainObjPtr vm,
                             virDomainGraphicsDefPtr dev);
int qemuDomainChangeGraphicsPasswords(virQEMUDriverPtr driver,
                                      virDomainObjPtr vm,
                                      int type,
                                      virDomainGraphicsAuthDefPtr auth,
                                      const char *defaultPasswd);
int qemuDomainChangeNet(virQEMUDriverPtr driver,
                        virDomainObjPtr vm,
                        virDomainPtr dom,
                        virDomainDeviceDefPtr dev);
int qemuDomainChangeNetLinkState(virQEMUDriverPtr driver,
                                 virDomainObjPtr vm,
                                 virDomainNetDefPtr dev,
                                 int linkstate);
int qemuDomainDetachVirtioDiskDevice(virQEMUDriverPtr driver,
                                     virDomainObjPtr vm,
                                     virDomainDeviceDefPtr dev);
int qemuDomainDetachDiskDevice(virQEMUDriverPtr driver,
                               virDomainObjPtr vm,
                               virDomainDeviceDefPtr dev);
int qemuDomainDetachPciControllerDevice(virQEMUDriverPtr driver,
                                        virDomainObjPtr vm,
                                        virDomainDeviceDefPtr dev);
int qemuDomainDetachNetDevice(virQEMUDriverPtr driver,
                              virDomainObjPtr vm,
                              virDomainDeviceDefPtr dev);
int qemuDomainDetachHostDevice(virQEMUDriverPtr driver,
                               virDomainObjPtr vm,
                               virDomainDeviceDefPtr dev);
int qemuDomainAttachLease(virQEMUDriverPtr driver,
                          virDomainObjPtr vm,
                          virDomainLeaseDefPtr lease);
int qemuDomainDetachLease(virQEMUDriverPtr driver,
                          virDomainObjPtr vm,
                          virDomainLeaseDefPtr lease);


#endif /* __QEMU_HOTPLUG_H__ */
