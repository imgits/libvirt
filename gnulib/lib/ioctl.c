/* ioctl.c --- wrappers for Windows ioctl function

   Copyright (C) 2008-2012 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published by
   the Free Software Foundation; either version 2.1 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* Written by Paolo Bonzini */

#include <config.h>

#include <sys/ioctl.h>

#include <stdarg.h>

#if HAVE_IOCTL

/* Provide a wrapper with the POSIX prototype.  */
# undef ioctl
int
rpl_ioctl (int fd, int request, ... /* {void *,char *} arg */)
{
  void *buf;
  va_list args;

  va_start (args, request);
  buf = va_arg (args, void *);
  va_end (args);

  /* Cast 'request' so that when the system's ioctl function takes a 64-bit
     request argument, the value gets zero-extended, not sign-extended.  */
  return ioctl (fd, (unsigned int) request, buf);
}

#else /* mingw */

# include <errno.h>

# include "fd-hook.h"

static int
primary_ioctl (int fd, int request, void *arg)
{
  /* We don't support FIONBIO on pipes here.  If you want to make pipe
     fds non-blocking, use the gnulib 'nonblocking' module, until
     gnulib implements fcntl F_GETFL / F_SETFL with O_NONBLOCK.  */

  errno = ENOSYS;
  return -1;
}

int
ioctl (int fd, int request, ... /* {void *,char *} arg */)
{
  void *arg;
  va_list args;

  va_start (args, request);
  arg = va_arg (args, void *);
  va_end (args);

# if WINDOWS_SOCKETS
  return execute_all_ioctl_hooks (primary_ioctl, fd, request, arg);
# else
  return primary_ioctl (fd, request, arg);
# endif
}

#endif
