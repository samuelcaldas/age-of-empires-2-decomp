#include <cstring>

void test_perimeter_point_null_and_zero();
void test_perimeter_point_deduplication_and_capacity();
void test_perimeter_point_many_points();
void test_raster_serialize_zero_extents();
void test_raster_serialize_multiple_extents();
void test_raster_deserialize_round_trip();
void test_rect_update_calculations_and_mask_subtraction();
void test_raster_untag_clears_cells();
void test_raster_trace_backtracking();
void test_raster_extent_resolution();

int main(int argc, char **argv) {
    if (argc < 2) {
        test_perimeter_point_null_and_zero();
        test_perimeter_point_deduplication_and_capacity();
        test_perimeter_point_many_points();
        test_raster_serialize_zero_extents();
        test_raster_serialize_multiple_extents();
        test_raster_deserialize_round_trip();
        test_rect_update_calculations_and_mask_subtraction();
        test_raster_untag_clears_cells();
        test_raster_trace_backtracking();
        test_raster_extent_resolution();
        return 0;
    }

    const char *n = argv[1];
    if (std::strcmp(n, "perimeter_null_zero") == 0) test_perimeter_point_null_and_zero();
    else if (std::strcmp(n, "perimeter_dedup_cap") == 0) test_perimeter_point_deduplication_and_capacity();
    else if (std::strcmp(n, "perimeter_many") == 0) test_perimeter_point_many_points();
    else if (std::strcmp(n, "serialize_zero") == 0) test_raster_serialize_zero_extents();
    else if (std::strcmp(n, "serialize_many") == 0) test_raster_serialize_multiple_extents();
    else if (std::strcmp(n, "deserialize_roundtrip") == 0) test_raster_deserialize_round_trip();
    else if (std::strcmp(n, "rect_update") == 0) test_rect_update_calculations_and_mask_subtraction();
    else if (std::strcmp(n, "raster_untag") == 0) test_raster_untag_clears_cells();
    else if (std::strcmp(n, "raster_trace") == 0) test_raster_trace_backtracking();
    else if (std::strcmp(n, "raster_extent") == 0) test_raster_extent_resolution();
    else return 1;

    return 0;
}
