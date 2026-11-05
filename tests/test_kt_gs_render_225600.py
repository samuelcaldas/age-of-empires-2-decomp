import unittest

class TestKtGsRender225600(unittest.TestCase):
    def test_imports(self):
        import kt_gs_render_225600_matching_support
        self.assertIsNotNone(kt_gs_render_225600_matching_support)

if __name__ == "__main__":
    unittest.main()
