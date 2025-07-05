import { useState, useEffect } from 'react';
import './ThemeToggle.css';

const ThemeToggle = () => {
  const [theme, setTheme] = useState('auto');

  useEffect(() => {
    // Load theme from localStorage or default to 'auto'
    const savedTheme = localStorage.getItem('theme') || 'auto';
    setTheme(savedTheme);
    applyTheme(savedTheme);
  }, []);

  const applyTheme = (theme) => {
    const root = document.documentElement;
    
    // Remove any existing theme classes
    root.classList.remove('light', 'dark');
    
    if (theme === 'light') {
      root.classList.add('light');
    } else if (theme === 'dark') {
      root.classList.add('dark');
    }
    // For 'auto', rely on CSS media queries
  };

  const handleThemeChange = (newTheme) => {
    setTheme(newTheme);
    localStorage.setItem('theme', newTheme);
    applyTheme(newTheme);
  };

  return (
    <div className="theme-toggle">
      <button
        className={`theme-btn ${theme === 'light' ? 'active' : ''}`}
        onClick={() => handleThemeChange('light')}
        title="Light Mode"
      >
        ☀️
      </button>
      <button
        className={`theme-btn ${theme === 'auto' ? 'active' : ''}`}
        onClick={() => handleThemeChange('auto')}
        title="Auto Mode"
      >
        🌗
      </button>
      <button
        className={`theme-btn ${theme === 'dark' ? 'active' : ''}`}
        onClick={() => handleThemeChange('dark')}
        title="Dark Mode"
      >
        🌙
      </button>
    </div>
  );
};

export default ThemeToggle;