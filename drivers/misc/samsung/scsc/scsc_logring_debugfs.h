/****************************************************************************
 *
 *   Copyright (c) 2016 Samsung Electronics Co., Ltd. All rights reserved.
 *
 ****************************************************************************/

#ifndef _SCSC_LOGRING_DEBUGFS_H_
#define _SCSC_LOGRING_DEBUGFS_H_

#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/module.h>
#include <linux/debugfs.h>
#include <linux/version.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>

#include <scsc/scsc_logring.h>
#include "scsc_logring_ring.h"

#define STATSTR_SZ				256
#define SCSC_DEBUGFS_ROOT			"scsc"
#define SCSC_SAMSG_FNAME			"samsg"
#define SCSC_SAMLOG_FNAME			"samlog"
#define SCSC_STAT_FNAME				"stat"
#define SCSC_SAMWRITE_FNAME			"samwrite"

#define SAMWRITE_BUFSZ				2048
#define SCSC_DEFAULT_MAX_RECORDS_PER_READ	1

struct scsc_ibox {
	struct scsc_ring_buffer *rb;
	char                    *tbuf;
	size_t			  tsz;
	bool		      tbuf_vm;
	size_t			t_off;
	size_t		       t_used;
	size_t		 cached_reads;
	loff_t			f_pos;
};

struct scsc_debugfs_info {
	struct dentry *rootdir;
	struct dentry *bufdir;
	struct dentry *samsgfile;
	struct dentry *samlogfile;
	struct dentry *statfile;
	struct dentry *samwritefile;
};

struct write_config {
	char   *fmt;
	size_t buf_sz;
	char   buf[SAMWRITE_BUFSZ];
};

void *samlog_debugfs_init(const char *name, void *rb) __init;
void samlog_debugfs_exit(void **priv) __exit;

#endif /* _SCSC_LOGRING_DEBUGFS_H_ */
