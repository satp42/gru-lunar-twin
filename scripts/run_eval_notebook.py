#!/usr/bin/env python3

import sys
sys.path.append('.')
import subprocess
import os

def run_notebook():
    """Execute the evaluation notebook"""
    print("Running evaluation notebook...")
    
    # Change to rl/eval directory
    os.chdir('rl/eval')
    
    try:
        # Execute notebook using nbconvert
        result = subprocess.run([
            'jupyter', 'nbconvert', 
            '--to', 'notebook',
            '--execute',
            '--inplace',
            'reward.ipynb'
        ], capture_output=True, text=True, check=True)
        
        print("✅ Notebook executed successfully")
        print("✅ Plots generated and saved")
        
        # Check if the image was created
        if os.path.exists('fleet_reward_evaluation.png'):
            print("✅ Screenshot saved: rl/eval/fleet_reward_evaluation.png")
            return True
        else:
            print("❌ Screenshot not found")
            return False
            
    except subprocess.CalledProcessError as e:
        print(f"❌ Error running notebook: {e}")
        print(f"stdout: {e.stdout}")
        print(f"stderr: {e.stderr}")
        return False
    except Exception as e:
        print(f"❌ Unexpected error: {e}")
        return False

if __name__ == "__main__":
    success = run_notebook()
    sys.exit(0 if success else 1) 