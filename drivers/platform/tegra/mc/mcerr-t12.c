/*
 * Tegra 12x SoC-specific mcerr code.
 *
 * Copyright (c) 2012-2014, NVIDIA Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <tegra/mcerr.h>
#include <dt-bindings/memory/tegra-swgroup.h>

/*** Auto generated by `mcp.pl'. Do not modify! ***/

struct mc_client mc_clients[] = {
	client("ptc", "csr_ptcr", INVALID),
	client("dc", "csr_display0a", DC),
	client("dcb", "csr_display0ab", DCB),
	client("dc", "csr_display0b", DC),
	client("dcb", "csr_display0bb", DCB),
	client("dc", "csr_display0c", DC),
	client("dcb", "csr_display0cb", DCB),
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	client("afi", "csr_afir", AFI),
	client("avpc", "csr_avpcarm7r", AVPC),
	client("dc", "csr_displayhc", DC),
	client("dcb", "csr_displayhcb", DCB),
	dummy_client,
	dummy_client,
	dummy_client,
	client("hda", "csr_hdar", HDA),
	client("hc", "csr_host1xdmar", HC),
	client("hc", "csr_host1xr", HC),
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	client("msenc", "csr_msencsrd", MSENC),
	client("ppcs", "csr_ppcsahbdmar", PPCS),
	client("ppcs", "csr_ppcsahbslvr", PPCS),
	client("sata", "csr_satar", SATA),
	dummy_client,
	dummy_client,
	client("vde", "csr_vdebsevr", VDE),
	client("vde", "csr_vdember", VDE),
	client("vde", "csr_vdemcer", VDE),
	client("vde", "csr_vdetper", VDE),
	client("mpcorelp", "csr_mpcorelpr", INVALID),
	client("mpcore", "csr_mpcorer", INVALID),
	dummy_client,
	dummy_client,
	dummy_client,
	client("msenc", "csw_msencswr", MSENC),
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	client("afi", "csw_afiw", AFI),
	client("avpc", "csw_avpcarm7w", AVPC),
	dummy_client,
	dummy_client,
	client("hda", "csw_hdaw", HDA),
	client("hc", "csw_host1xw", HC),
	dummy_client,
	client("mpcorelp", "csw_mpcorelpw", INVALID),
	client("mpcore", "csw_mpcorew", INVALID),
	dummy_client,
	client("ppcs", "csw_ppcsahbdmaw", PPCS),
	client("ppcs", "csw_ppcsahbslvw", PPCS),
	client("sata", "csw_sataw", SATA),
	client("vde", "csw_vdebsevw", VDE),
	client("vde", "csw_vdedbgw", VDE),
	client("vde", "csw_vdembew", VDE),
	client("vde", "csw_vdetpmw", VDE),
	dummy_client,
	dummy_client,
	client("isp2", "csr_ispra", ISP2),
	dummy_client,
	client("isp2", "csw_ispwa", ISP2),
	client("isp2", "csw_ispwb", ISP2),
	dummy_client,
	dummy_client,
	client("xusb_host", "csr_xusb_hostr", XUSB_HOST),
	client("xusb_host", "csw_xusb_hostw", XUSB_HOST),
	client("xusb_dev", "csr_xusb_devr", XUSB_DEV),
	client("xusb_dev", "csw_xusb_devw", XUSB_DEV),
	client("isp2b", "csr_isprab", ISP2B),
	dummy_client,
	client("isp2b", "csw_ispwab", ISP2B),
	client("isp2b", "csw_ispwbb", ISP2B),
	dummy_client,
	dummy_client,
	client("tsec", "csr_tsecsrd", TSEC),
	client("tsec", "csw_tsecswr", TSEC),
	client("a9avp", "csr_a9avpscr", A9AVP),
	client("a9avp", "csw_a9avpscw", A9AVP),
	client("gpu", "csr_gpusrd", GPU),
	client("gpu", "csw_gpuswr", GPU),
	client("dc", "csr_displayt", DC),
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	client("sdmmc1a", "csr_sdmmcra", SDMMC1A),
	client("sdmmc2a", "csr_sdmmcraa", SDMMC2A),
	client("sdmmc3a", "csr_sdmmcr", SDMMC3A),
	client("sdmmc4a", "csr_sdmmcrab", SDMMC4A),
	client("sdmmc1a", "csw_sdmmcwa", SDMMC1A),
	client("sdmmc2a", "csw_sdmmcwaa", SDMMC2A),
	client("sdmmc3a", "csw_sdmmcw", SDMMC3A),
	client("sdmmc4a", "csw_sdmmcwab", SDMMC4A),
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	client("vic", "csr_vicsrd", VIC),
	client("vic", "csw_vicswr", VIC),
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	client("vi", "csw_viw", VI),
	client("dc", "csr_displayd", DC),
};
int mc_client_last = ARRAY_SIZE(mc_clients) - 1;
/*** Done. ***/

static void mcerr_t12x_info_update(struct mc_client *c, u32 stat)
{
	if (stat & MC_INT_DECERR_EMEM)
		c->intr_counts[0]++;
	if (stat & MC_INT_SECURITY_VIOLATION)
		c->intr_counts[1]++;
	if (stat & MC_INT_INVALID_SMMU_PAGE)
		c->intr_counts[2]++;
	if (stat & MC_INT_INVALID_APB_ASID_UPDATE)
		c->intr_counts[3]++;
	if (stat & MC_INT_DECERR_VPR)
		c->intr_counts[4]++;
	if (stat & MC_INT_SECERR_SEC)
		c->intr_counts[5]++;
	if (stat & MC_INT_DECERR_MTS)
		c->intr_counts[6]++;

	if (stat & ~mc_int_mask)
		c->intr_counts[7]++;
}

#define fmt_hdr "%-18s %-18s %-9s %-9s %-9s %-10s %-10s %-10s %-10s %-9s\n"
#define fmt_cli "%-18s %-18s %-9u %-9u %-9u %-10u %-10u %-10u %-10u %-9u\n"
static int mcerr_t12x_debugfs_show(struct seq_file *s, void *v)
{
	int i, j;
	int do_print;

	seq_printf(s, fmt_hdr,
		   "swgroup", "client", "decerr", "secerr", "smmuerr",
		   "apberr", "decerr-VPR", "secerr-SEC",
		   "decerr-MTS", "unknown");
	for (i = 0; i < ARRAY_SIZE(mc_clients); i++) {
		do_print = 0;
		if (strcmp(mc_clients[i].name, "dummy") == 0)
			continue;
		/* Only print clients who actually have errors. */
		for (j = 0; j < mc_intr_count; j++) {
			if (mc_clients[i].intr_counts[j]) {
				do_print = 1;
				break;
			}
		}
		if (do_print)
			seq_printf(s, fmt_cli,
				   mc_clients[i].swgroup,
				   mc_clients[i].name,
				   mc_clients[i].intr_counts[0],
				   mc_clients[i].intr_counts[1],
				   mc_clients[i].intr_counts[2],
				   mc_clients[i].intr_counts[3],
				   mc_clients[i].intr_counts[4],
				   mc_clients[i].intr_counts[5],
				   mc_clients[i].intr_counts[6],
				   mc_clients[i].intr_counts[7]);
	}
	return 0;
}

/*
 * Set up chip specific functions and data for handling this particular chip's
 * error decoding and logging.
 */
void mcerr_chip_specific_setup(struct mcerr_chip_specific *spec)
{
	spec->mcerr_info_update = mcerr_t12x_info_update;
	spec->mcerr_debugfs_show = mcerr_t12x_debugfs_show;
	spec->nr_clients = ARRAY_SIZE(mc_clients);
	return;
}

